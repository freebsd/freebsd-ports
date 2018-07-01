# makefile for use of:	sendmail milter lib
# Date created:		08 Nov 2006
# Whom:			dinoex
#
# $FreeBSD$
#
# a port shall includes this file after bsd.ports.pre.mk
# .include "${PORTSDIR}/${PKGCATEGORY}/sendmail/bsd.milter.mk"
#
# the user/port can now set this options in the makefiles.
#
# WITH_MILTER_STATIC=		- Use static milter lib
# WITHOUT_MILTER_CFLAGS=	- do not set CFLAGS
# WITHOUT_MILTER_LDFLAGS=	- do not set LDFLAGS
#
# WITH_MILTER_BASE=yes		- Use milter in the base
# WITH_MILTER_PORT=yes		- Use milter from ports
#
# If unspecified, check for the lib exist in the base system,
# but gives an installed port preference over it.
#
#
# Overrideable defaults:
#
# SENDMAIL_MILTER_PORT?=	libmilter
#
# The makefile sets this variables:
# MILTERBASE		- "/usr" or ${LOCALBASE}
# MILTERINC		- path to the matching includes
# MILTERLIB		- path to the libs
# MILTERRPATH		- rpath for dynamic linker
# 
# The makefile extend this variables:
# LIB_DEPENDS
# BUILD_DEPENDS
# CFLAGS
# LDFLAGS
#
# MAKE_ENV		- extended with the variables above
# CONFIGURE_ENV		- extended with LDFLAGS
# BUILD_DEPENDS		- are added if needed
# RUN_DEPENDS		- are added if needed

Milter_Include_MAINTAINER=	dinoex@FreeBSD.org

.  if	!defined(WITH_MILTER_BASE) && \
	!defined(WITH_MILTER_PORT)
.   if	!defined(WITH_SENDMAIL_BASE) && \
	!defined(WITH_SENDMAIL_PORT)
.     if	exists(${LOCALBASE}/lib/libmilter.a) || \
		!exists(/usr/lib/libmilter.a)
WITH_MILTER_PORT=yes
WITH_SENDMAIL_PORT=yes
.     else
WITH_MILTER_BASE=yes
WITH_SENDMAIL_BASE=yes
.     endif
.   else
# convert old macros to new
.     if	defined(WITH_SENDMAIL_PORT)
WITH_MILTER_PORT=yes
.     endif
.     if	defined(WITH_SENDMAIL_BASE)
WITH_MILTER_BASE=yes
.     endif
.   endif
.endif

.if defined(WITH_MILTER_PORT)

.  if defined(WITH_MILTER_STATIC) || defined(WITH_SENDMAIL_STATIC_MILTER)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:mail/${SENDMAIL_MILTER_PORT}
.  else
LIB_DEPENDS+=	libmilter.so.${MILTER_SOVER}:mail/${SENDMAIL_MILTER_PORT}
.  endif

SENDMAIL_MILTER_PORT?=	libmilter
MILTER_SOVER?=	7
MILTERBASE?=	${LOCALBASE}
MILTERRPATH=	${MILTERBASE}/lib

.endif

.if defined(WITH_MILTER_BASE)
MILTERBASE?=	/usr
MILTERRPATH=	${DESTDIR}/usr/lib:${LOCALBASE}/lib

.if !exists(/usr/lib/libmilter.a)
BROKEN=		Base system sendmail not found or too old, rebuild with WITH_SENDMAIL_PORT=yes
.endif

.endif

MILTERINC=	-I${MILTERBASE}/include
.if !defined(WITHOUT_MILTER_CFLAGS)
.  if defined(CFLAGS)
CFLAGS+=${MILTERINC}
.  else
CFLAGS=${MILTERINC}
.  endif
.endif

MILTERLIB=	-L${MILTERBASE}/lib
.if !defined(WITHOUT_MILTER_LDFLAGS)
LDFLAGS+=	-Wl,-rpath,${MILTERRPATH} ${MILTERLIB}
.endif

# eof

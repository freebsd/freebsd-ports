# New ports collection makefile for:	xfmail
# Date created:		30 June 1996
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xfmail
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://xfmail.cfreeze.com/pub/xfmail/release/%SUBDIR%/	\
		ftp://cupido.geophys.nat.tu-bs.de/pub/xfmail/release/%SUBDIR%/	\
		ftp://xfmail.ufies.org/pub/xfmail/release/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}rc1/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-rc1

MAINTAINER=	mikeh@FreeBSD.org
COMMENT=	An X Window System application for receiving electronic mail

BUILD_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_AUTOMAKE_VER=	15
USE_AUTOCONF=	yes
USE_BZIP2=	yes
USE_GNOME=	glib12
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

AUTOCONF=	autoconf
AUTOHEADER=	autoheader
ACLOCAL=	aclocal

# XXX: Disable patching for libtool until we can generate the files
LIBTOOLFILES=

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--with-dbm-lib=gdbm

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--with-esd-sound
.endif

.if defined(WITH_FACES)
LIB_DEPENDS+=	compface:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=	--with-faces
.endif

MAN1=		xfmail.1

pre-everything::
	@echo
.ifndef(WITH_ESOUND)
	@echo "To build with esound support, restart make and define WITH_ESOUND"
.endif
.ifndef(WITH_FACES)
	@echo "To build with faces support, restart make and define WITH_FACES"
.endif
	@echo

pre-configure:
	@(cd ${WRKSRC} && ${SH} autogen.sh);	\
	${MAKE} LIBTOOLFILES=aclocal.m4 patch-libtool

.include <bsd.port.post.mk>

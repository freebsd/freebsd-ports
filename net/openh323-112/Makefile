# New ports collection makefile for:	openh323
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openh323-112
PORTVERSION=	1.12.2
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ 
DISTNAME=	${NAME}_${PORTVERSION}

MAINTAINER=	db@db.net
COMMENT=	A H323 Video Conferencing library

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/pwlib152:build
LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

NAME=	openh323

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
# Check for telephony.h in the two places the source is hard coded to check
# /usr/include/sys and /usr/local/include/sys
# If it is not present, extract it from the comms/ixj port
.if !exists(/usr/include/sys/telephony.h)
.if !exists(/usr/local/include/sys/telephony.h)
PATCH_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/comms/ixj:patch
.endif
.endif
.endif

WRKSRC=		${WRKDIR}/${NAME}

PLIST_FILES=	bin/simph323
USE_BISON=	yes

USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=	yes
PWLIBDIR!=	cd ${PORTSDIR}/devel/pwlib152 && make -V WRKSRC
CONFIGURE_ENV=	PWLIBDIR=${PWLIBDIR} OPENH323DIR=${WRKSRC}
ALL_TARGET=	optnoshared
MAKE_ENV=	PWLIBDIR=${PWLIBDIR} OPENH323DIR=${WRKSRC}
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

post-patch:
.if ${OSVERSION} < 500000
.if !exists(/usr/include/sys/telephony.h)
.if !exists(/usr/local/include/sys/telephony.h)
	# Copy ixj driver include files into OpenH323 include directory
	${MKDIR} ${WRKDIR}/openh323/include/sys
	${CP} ${WRKDIRPREFIX}${.CURDIR}/../../comms/ixj/work/ixj_freebsd/telephony.h ${WRKDIR}/openh323/include/sys
	${CP} ${WRKDIRPREFIX}${.CURDIR}/../../comms/ixj/work/ixj_freebsd/ixjuser.h ${WRKDIR}/openh323/include/sys
.endif
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/samples/simple/obj_${OPSYS}_${THE_MACHTYPE}_r/simph323 ${PREFIX}/bin

.include <bsd.port.post.mk>

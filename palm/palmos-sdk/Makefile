# New ports collection makefile for:	Palm OS SDK
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palmos-sdk
PORTVERSION=	${SDKVER}r3
CATEGORIES=	palm
MASTER_SITES=
DISTFILES=	palmos-sdk-${SDKVER}r3-1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Palm OS SDK

RESTRICTED=	License agreement is required.
WRKSRC=		${WRKDIR}/sdk-5r3
NO_BUILD=	YES
PLIST_SUB=	BASEDIR=palmdev/sdk-${SDKVER}

SDKVER=		5.0
INCDIR=		${PREFIX}/palmdev/sdk-${SDKVER}/include
LIBDIR=		${PREFIX}/palmdev/sdk-${SDKVER}/lib

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/palmos-sdk-${SDKVER}r3-1.tar.gz)
IGNORE='You must manually fetch tarball from http://www.palmos.com/cgi-bin/sdk50.cgi and place it in ${DISTDIR} then run make again.'
.endif

do-install:
	${MKDIR} ${INCDIR} ${LIBDIR}
	${CP} -Rp ${WRKSRC}/include/* ${INCDIR}
	${CP} -Rp ${WRKSRC}/lib/* ${LIBDIR}
	${CP} -p "${WRKSRC}/Palm License.txt" "${WRKSRC}/PalmOS 5 SDK 68K R3 Readme.txt" ${PREFIX}/palmdev/sdk-${SDKVER}/
	${CHOWN} -R root:wheel ${INCDIR} ${LIBDIR}

.include <bsd.port.post.mk>

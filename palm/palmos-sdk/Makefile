# New ports collection makefile for:	Palm OS SDK
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palmos-sdk
PORTVERSION=	4.0
CATEGORIES=	palm
MASTER_SITES=
DISTFILES=	sdk40-core.tar.gz sdk40upd1.tar.gz

MAINTAINER=	kuriyama@FreeBSD.org

RESTRICTED=	License agreement is required.
WRKSRC=		${WRKDIR}/Palm\ OS\ Support
UPDSRC=		${WRKDIR}/PalmOS-4.0-SDK-Update-1
NO_BUILD=	YES

INCDIR=		${PREFIX}/palmdev/sdk-4.0/include
LIBDIR=		${PREFIX}/palmdev/sdk-4.0/lib

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/sdk40-core.tar.gz) || !exists(${DISTDIR}/sdk40upd1.tar.gz)
IGNORE='You must manually fetch tarball from http://www.palmos.com/dev/tech/tools/ and place it in ${DISTDIR} then run make again.'
.endif

do-install:
	${MKDIR} ${INCDIR} ${LIBDIR}
	${CP} -Rp ${WRKSRC}/Incs/* ${INCDIR}
	${CP} -Rp ${WRKSRC}/GCC\ Libraries/* ${LIBDIR}
	${CP} -Rp ${UPDSRC}/PalmOS-Unix/PalmOS-Support/include/* ${INCDIR}
	${CP} -Rp ${UPDSRC}/PalmOS-Unix/PalmOS-Support/lib/* ${LIBDIR}
	${CHOWN} -R root:wheel ${INCDIR} ${LIBDIR}

.include <bsd.port.post.mk>

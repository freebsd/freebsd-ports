# New ports collection makefile for:	Palm OS SDK
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palmos-sdk
PORTVERSION=	3.5
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	
DISTFILES=	sdk35.tar.gz sdk35-update1.tar.gz

MAINTAINER=	kuriyama@FreeBSD.org

RESTRICTED=	License agreement is required.
WRKSRC=		${WRKDIR}/Palm\ OS\ 3.5\ Support
NO_BUILD=	YES

INCDIR=		${PREFIX}/palmdev/sdk-3.5/include
LIBDIR=		${PREFIX}/palmdev/sdk-3.5/lib

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/sdk35.tar.gz) || !exists(${DISTDIR}/sdk35-update1.tar.gz)
IGNORE='You must manually fetch tarball from http://www.palmos.com/dev/tech/tools/ and place it in ${DISTDIR} then run make again.'
.endif

do-install:
	${MKDIR} ${INCDIR} ${LIBDIR}
	${CP} -Rp ${WRKSRC}/Incs/* ${INCDIR}
	${CP} -Rp ${WRKSRC}/GCC\ Libraries/* ${LIBDIR}
	${CHOWN} -R root.wheel ${INCDIR} ${LIBDIR}

.include <bsd.port.post.mk>

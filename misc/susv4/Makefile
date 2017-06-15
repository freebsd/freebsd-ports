# Based on a port created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	susv4
PORTVERSION=	20160930
CATEGORIES=	misc
MASTER_SITES=	#
DISTNAME=	susv4tc2
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Open Group Base Specifications Issue 7/IEEE Std 1003.1, 2016 Edition

LICENSE=	NONE

RESTRICTED=	Redistribution of the documents is not permitted

USES=		tar:bzip2
NO_ARCH=	yes
NO_BUILD=	yes
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be redistributed because of licensing reasons. Please visit http://www.unix.org/online.html to accept their license and download ${DISTFILES} into ${DISTDIR}/${DIST_SUBDIR}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

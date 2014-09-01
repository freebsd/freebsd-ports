# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	susv3
PORTVERSION=	1.2
CATEGORIES=	misc
MASTER_SITES=	#
DISTNAME=	susv3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Single UNIX Specification Version 3

RESTRICTED=	Redistribution of the documents is not permitted

USES=		tar:bzip2
NO_BUILD=	yes
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be redistributed because of licensing reasons. Please visit http://www.unix-systems.org/version3/online.html to accept their license and download ${DISTFILES} into ${DISTDIR}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

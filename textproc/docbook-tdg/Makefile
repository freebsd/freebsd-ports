# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook-tdg
PORTVERSION=	2.0.17
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/tdg/en/
DISTNAME=	tdg-en-html-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Norman Walsh's book "DocBook: The Definitive Guide"

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tdg/en

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

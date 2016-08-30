# Created by: tundra
# $FreeBSD$

PORTNAME=	mailfmt
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.tundraware.com/Software/mailfmt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remove leading quotations from mail/news and wrap lines to fixed width

USES=		python
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE= DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/mailfmt-license.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

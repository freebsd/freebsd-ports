# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vimpager
DISTVERSION=	2.06
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use ViM as a pager

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	vim:editors/vim

USE_GITHUB=	yes
GH_ACCOUNT=	rkitover
GH_TAGNAME=	d0bf869

PLIST_FILES=	bin/vimcat bin/${PORTNAME} etc/${PORTNAME}rc
PORTDOCS=	vimcat.md vimpager.md
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

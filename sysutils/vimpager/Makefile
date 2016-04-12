# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vimpager
DISTVERSION=	2.06
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use ViM as a pager

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	vim:editors/vim

USE_GITHUB=	yes
GH_ACCOUNT=	rkitover
GH_TAGNAME=	d0bf869

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/vimcat bin/${PORTNAME} etc/${PORTNAME}rc
PORTDOCS=	vimcat.md vimpager.md

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

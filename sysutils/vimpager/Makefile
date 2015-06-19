# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vimpager
PORTVERSION=	2.05
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use ViM as a pager

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

USE_GITHUB=	yes
GH_ACCOUNT=	rkitover

OPTIONS_DEFINE=		VIMCAT DOCS
OPTIONS_DEFAULT=	VIMCAT DOCS

VIMCAT_DESC=		Install vimcat(1) (requires shells/bash)
VIMCAT_RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
VIMCAT_PLIST_FILES=	bin/vimcat

PLIST_FILES=		bin/${PORTNAME} etc/${PORTNAME}rc
PORTDOCS=		vimcat.md vimpager.md

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

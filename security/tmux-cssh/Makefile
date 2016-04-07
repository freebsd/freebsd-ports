# $FreeBSD$

PORTNAME=	tmux-cssh
PORTVERSION=	20151014
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	jrm@ftfl.ca
COMMENT=	ClusterSSH features using tmux, but not X11

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LOCALBASE}/bin/tmux:sysutils/tmux

NO_BUILD=	YES

USE_GITHUB=	yes
GH_ACCOUNT=	dennishafemann
GH_TAGNAME=	2175073

PLIST_FILES=	bin/tmux-cssh %%PORTDOCS%%%%DOCSDIR%%/README.md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tmux-cssh ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

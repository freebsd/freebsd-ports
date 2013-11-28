# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faup
PORTVERSION=	1.4
CATEGORIES=	www devel
MASTER_SITES=	http://github.com/stricaud/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Fast URL decoder library

LICENSE=	WTFPL
LICENSE_NAME=	Do What The [expletive] You Want To Public License, Version 2
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FETCH_ARGS=	-Fpr
USES=		cmake:outsource
USE_LDCONFIG=	yes
USE_LUA=	5.1

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

PORTNAME=	slurm
DISTVERSION=	0.4.4
CATEGORIES=	net

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Generic network load monitor
WWW=		https://github.com/mattthias/slurm/wiki/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	mattthias
GH_TAGNAME=	upstream/${DISTVERSION}

PORTDOCS=	AUTHORS COPYING COPYRIGHT ChangeLog FAQ KEYS README.md \
		THANKS THEMES.txt TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

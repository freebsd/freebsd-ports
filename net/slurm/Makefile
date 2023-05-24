PORTNAME=	slurm
DISTVERSIONPREFIX=	upstream/
DISTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Generic network load monitor
WWW=		https://github.com/mattthias/slurm/wiki/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	mattthias

PORTDOCS=	AUTHORS COPYING COPYRIGHT ChangeLog FAQ KEYS README.md THANKS \
		THEMES.txt TODO

OPTIONS_DEFINE=	DOCS

post-build:
	cd ${WRKSRC} && mandoc -mdoc -T man slurm.1 > slurm.1.tmp && \
		${MV} slurm.1.tmp slurm.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

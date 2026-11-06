PORTNAME=	gambit
DISTVERSION=	16.7.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/gambitproject/gambit/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of tools for doing computation in game theory
WWW=		http://www.gambit-project.org \
		https://github.com/gambitproject/gambit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gnome
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_WX=		3.0
USE_CXXSTD=	c++17
WX_CONF_ARGS=	absolute

test-quick:
	@if [ "$$(${ECHO} 'NFG 1 R "PD" { "P1" "P2" } { 2 2 } 2 2 0 3 3 0 1 1' | ${STAGEDIR}${PREFIX}/bin/gambit-enumpure)" = "NE,1,0,1,0" ]; then \
		${ECHO_MSG} "Test succeeded"; \
	else \
		${ECHO_MSG} "Test failed"; \
		exit 1; \
	fi

.include <bsd.port.mk>

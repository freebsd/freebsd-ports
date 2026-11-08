PORTNAME=	optique
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	ports-mgmt

MAINTAINER=	sdalu@sdalu.com
COMMENT=	Fast ports options configurator for poudriere, synth and local builds
WWW=		https://github.com/sdalu/optique

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sdalu

PLIST_FILES=	bin/optique \
		share/man/man8/optique.8.gz

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/optique.8 ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.mk>

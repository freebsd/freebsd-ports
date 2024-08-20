PORTNAME=	ncrystal
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.2
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for thermal neutron transport in crystals and other materials
WWW=		https://mctools.github.io/ncrystal/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mctools

SHEBANG_FILES=	scripts/* \
		cmake/ncrystal-config.in

post-install: # workaround for https://github.com/mctools/ncrystal/issues/150
	@${RM} ${STAGEDIR}${PREFIX}/*.sh

.include <bsd.port.mk>

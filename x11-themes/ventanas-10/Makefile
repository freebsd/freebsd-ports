PORTNAME=	ventanas-10
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11-themes

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Openbox theme with a look similar to Windows 10

LICENSE=        GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=    openbox:x11-wm/openbox

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF
GH_PROJECT=	Ventanas-10

NO_ARCH=        yes
NO_BUILD=       yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/ventanas-10/openbox-3
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/themes/ventanas-10/openbox-3 "-not ( -name README.md -o -name LICENSE )"

.include <bsd.port.mk>

PORTNAME=	openvpn-auth-script
DISTVERSION=	1.0.0.3
CATEGORIES=	security net net-vpn

MAINTAINER=	pdemon@gmail.com
COMMENT=	Generic script-based deferred auth plugin for OpenVPN

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/openvpn-plugin.h:security/openvpn

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	pdemonaco

PLIST_FILES=	lib/openvpn/plugins/openvpn-plugin-auth-script.so

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/openvpn-plugin-auth-script.so

.include <bsd.port.mk>

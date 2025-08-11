PORTNAME=	openvpn-auth-oauth2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.25.2
CATEGORIES=	security net net-vpn

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Management client for OpenVPN that handles SSO authentication
WWW=		https://github.com/jkroepke/openvpn-auth-oauth2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

EXTRACT_DEPENDS=	${BUILD_DEPENDS}

USES=		go:1.24,modules

GO_MODULE=	github.com/jkroepke/openvpn-auth-oauth2

SUB_FILES=	openvpn_auth_oauth2

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/openvpn-auth-oauth2 ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.example.yaml ${STAGEDIR}${ETCDIR}/openvpn-auth-oauth2.yml.sample
	${INSTALL_SCRIPT} ${WRKDIR}/openvpn_auth_oauth2 ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>

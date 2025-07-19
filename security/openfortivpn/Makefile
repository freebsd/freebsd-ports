PORTNAME=	openfortivpn
DISTVERSIONPREFIX=	v
DISTVERSION=	1.23.1
CATEGORIES=	security net-vpn

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Client for PPP+SSL VPN tunnel services
WWW=		https://github.com/adrienverge/openfortivpn

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		autoreconf cpe pkgconfig ssl
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	adrienverge

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_SED=${LOCALBASE}/bin/gsed \
		OPENSSL_CFLAGS=-I${OPENSSLINC} \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" \
		ac_cv_header_net_route_h=yes

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/config ${STAGEDIR}${ETCDIR}/config.sample
	${RM} ${STAGEDIR}${DATADIR}/config.template
	${RMDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

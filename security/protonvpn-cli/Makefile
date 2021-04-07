PORTNAME=	protonvpn-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	security net net-vpn

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ProtonVPN Command line tool

LICENSE=			MIT GPLv3
LICENSE_COMB=			multi
LICENSE_FILE_MIT=		${WRKSRC}/license.md
LICENSE_DISTFILES_MIT=		${DISTFILES:M*protonvpn-cli*}
LICENSE_DISTFILES_GPLv3=	${DISTFILES:M*scripts*}

RUN_DEPENDS=	bash:shells/bash \
		openvpn:security/openvpn \
		wget:ftp/wget \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	ProtonVPN
GH_PROJECT=	scripts:updateResolvConf
GH_TAGNAME=	d5d0be1:updateResolvConf

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/protonvpn-cli \
		bin/pvpn \
		etc/openvpn/update-resolv-conf

post-patch:
	${REINPLACE_CMD} s,\$$python,${PYTHON_CMD},g ${WRKSRC}/protonvpn-cli.sh
	${REINPLACE_CMD} s,wget,wget\ --ca-certificate\ ${LOCALBASE}/share/certs/ca-root-nss.crt,g ${WRKSRC}/protonvpn-cli.sh
	${REINPLACE_CMD} s,%%LOCALBASE%%,${LOCALBASE},g ${WRKSRC}/protonvpn-cli.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/protonvpn-cli.sh ${STAGEDIR}${PREFIX}/bin/protonvpn-cli
	${LN} -s ./protonvpn-cli ${STAGEDIR}${PREFIX}/bin/pvpn
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/openvpn
	${INSTALL_SCRIPT} ${WRKSRC_updateResolvConf}/update-resolv-conf.sh ${STAGEDIR}${PREFIX}/etc/openvpn/update-resolv-conf

.include <bsd.port.mk>

PORTNAME=	vpnc-scripts
PORTVERSION=	20220510
PORTREVISION=	1
CATEGORIES=	sysutils net-vpn
MASTER_SITES=	ftp://ftp.infradead.org/pub/${PORTNAME}/ \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Collection of scripts to setup routes and other changes for a VPN
WWW=		https://git.infradead.org/users/dwmw2/vpnc-scripts.git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/vpnc-script sbin/vpnc-script-sshd sbin/vpnc-script-ptrtd

post-patch:
	@${REINPLACE_CMD} -e 's|\(/etc/vpnc\)|${PREFIX}\1|' \
		${WRKSRC}/vpnc-script

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script-sshd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script-ptrtd ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>

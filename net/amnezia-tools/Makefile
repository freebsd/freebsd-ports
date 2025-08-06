PORTNAME=	amnezia-tools
PORTVERSION=	1.0.20241018
PORTREVISION=	1
CATEGORIES=	net net-vpn
MASTER_SITES=	https://github.com/amnezia-vpn/amneziawg-tools/

MAINTAINER=	vova@zote.me
COMMENT=	Fast, modern and secure VPN Tunnel with AmneziaVPN anti-detection
WWW=		https://github.com/amnezia-vpn/amneziawg-tools/

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	amnezia-vpn
GH_PROJECT=	amneziawg-tools
GH_TAGNAME=	v${PORTVERSION}

WRKSRC_SUBDIR=	src
MAKE_ARGS+=	DEBUG=no WITH_BASHCOMPLETION=yes WITH_SYSTEMDUNITS=no
MAKE_ENV+=	MANDIR="${PREFIX}/share/man" \
		SYSCONFDIR="${PREFIX}/etc"

USE_RC_SUBR=	amnezia

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|wg s|awg s|g' \
		${WRKSRC}/completion/wg-quick.bash-completion

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/etc/amnezia/amneziawg
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/awg

.include <bsd.port.mk>

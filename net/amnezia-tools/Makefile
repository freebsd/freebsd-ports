PORTNAME=	amnezia
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.20260812
CATEGORIES=	net net-vpn
PKGNAMESUFFIX=	-tools

MAINTAINER=	vova@zote.me
COMMENT=	Fast, modern and secure VPN Tunnel with AmneziaVPN anti-detection
WWW=		https://github.com/vgrebenschikov/amneziawg-tools/

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USES=		gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	vgrebenschikov
GH_PROJECT=	amneziawg-tools
GH_TAGNAME=	v3.1.20260812-fbsd-2
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	wg-quick/freebsd.bash

DEBUG?=	no

MAKE_ARGS+=	DEBUG=${DEBUG} \
		WITH_BASHCOMPLETION=yes \
		WITH_SYSTEMDUNITS=no
MAKE_ENV+=	MANDIR="${PREFIX}/share/man" \
		SYSCONFDIR="${PREFIX}/etc"

WRKSRC_SUBDIR=	src

post-patch:
	@${REINPLACE_CMD} -e 's|wg s|awg s|g; \
		s|/usr/local/etc/wireguard|${ETCDIR}|' \
		${WRKSRC}/completion/wg-quick.bash-completion
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|' \
		${WRKSRC}/wg-quick/freebsd.bash

post-install:
	@${RMDIR} ${STAGEDIR}${ETCDIR}/amneziawg
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/awg

.include <bsd.port.mk>

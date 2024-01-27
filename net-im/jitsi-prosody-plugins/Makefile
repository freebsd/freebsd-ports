PORTNAME=	jitsi
PORTVERSION=	2.0.9220
CATEGORIES=	net-im
PKGNAMESUFFIX=	-prosody-plugins

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Prosody plugins for Jitsi Meet
WWW=		https://github.com/jitsi/jitsi-meet/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	prosodyctl:net-im/prosody

USES=		cpe

CPE_VENDOR=	jitsi
CPE_PRODUCT=	meet

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-meet
GH_TAGNAME=	stable/jitsi-meet_9220

INSTALLPATH=	${PREFIX}/lib/jitsi-prosody-plugins

USERS=		${PORTNAME}
GROUPS=		${USERS}

post-extract:
	${INSTALL_DATA} ${FILESDIR}/prosody.cfg.lua.in \
		${WRKSRC}/prosody.cfg.lua
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/prosody.cfg.lua
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|' \
		${WRKSRC}/prosody.cfg.lua

do-install:
	${MKDIR} ${STAGEDIR}${INSTALLPATH}/token
	cd ${WRKSRC}/resources/prosody-plugins && \
		${INSTALL_DATA} *.lua ${STAGEDIR}${INSTALLPATH}
	cd ${WRKSRC}/resources/prosody-plugins/token && \
		${INSTALL_DATA} *.lua ${STAGEDIR}${INSTALLPATH}/token
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/prosody.cfg.lua \
		${STAGEDIR}${EXAMPLESDIR}/prosody.cfg.lua

.include <bsd.port.mk>

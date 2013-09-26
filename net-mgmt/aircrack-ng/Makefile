# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	aircrack-ng
DISTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://download.aircrack-ng.org/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	An 802.11 WEP and WPA-PSK keys cracking program

USES=		gmake
MAKE_ARGS+=	UNSTABLE=true			# build some extra tools
USE_OPENSSL=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	SQLITE
OPTIONS_SUB=	yes
SQLITE_DESC=	Use SQLite for storing pre-computed key tables

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
MAKE_ARGS+=	SQLITE=true
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif
.if ${ARCH} == "sparc64" && ${OSVERSION} > 900000
BROKEN=		Does not compile on sparc64-9
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|= /usr/local|= ${PREFIX}|' \
		-e 's|-I/usr/local|-I${LOCALBASE}|' \
		-e 's|^CC[[:blank:]]*|&?|' \
		-e 's|^RANLIB[[:blank:]]*|&?|' \
		-e 's|^AR[[:blank:]]*|&?|' \
			${WRKSRC}/common.mak
# Do not install scripts (Linux-specific) and their manpages
	@${REINPLACE_CMD} \
		-E '/scripts|@echo/d' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-E 's/air(driver|mon)-ng\.1 //' \
			${WRKSRC}/manpages/Makefile
	@${REINPLACE_CMD} \
		-e 's|-lpthread|${PTHREAD_LIBS}|' \
			${WRKSRC}/src/Makefile

.include <bsd.port.mk>

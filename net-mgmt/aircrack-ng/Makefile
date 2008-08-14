# New ports collection makefile for:	Aircrack-ng
# Date created:				2006-05-25
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	aircrack-ng
DISTVERSION=	1.0-rc1
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://download.aircrack-ng.org/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	An 802.11 WEP and WPA-PSK keys cracking program

USE_GMAKE=	yes
USE_OPENSSL=	yes
SUB_FILES=	pkg-message

MAN1=		aircrack-ng.1 airdriver-ng.1 airdecap-ng.1 aireplay-ng.1 \
		airodump-ng.1 airolib-ng.1 airmon-ng.1 airsev-ng.1 \
		airtun-ng.1 buddy-ng.1 easside-ng.1 ivstools.1 kstats.1 \
		makeivs-ng.1 packetforge-ng.1 wesside-ng.1

OPTIONS=	SQLITE	"Use SQLite for storing pre-computed key tables" off

.include <bsd.port.pre.mk>

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
MAKE_ARGS+=	SQLITE=true
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|= /usr/local|= ${PREFIX}|' \
		-e 's|-I/usr/local|-I${LOCALBASE}|' \
		-e 's|^CC[[:blank:]]*|&?|' \
		-e 's|^RANLIB[[:blank:]]*|&?|' \
		-e 's|^AR[[:blank:]]*|&?|' \
			${WRKSRC}/common.mak
# Do not install scripts (Linux-specific)
	@${REINPLACE_CMD} \
		-e '/$$(SCRIPTS)/d' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|-lpthread|${PTHREAD_LIBS}|' \
			${WRKSRC}/src/Makefile

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>

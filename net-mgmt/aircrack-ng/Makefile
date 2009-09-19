# New ports collection makefile for:	Aircrack-ng
# Date created:				2006-05-25
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	aircrack-ng
DISTVERSION=	1.0
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://download.aircrack-ng.org/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	An 802.11 WEP and WPA-PSK keys cracking program

USE_GMAKE=	yes
MAKE_ARGS+=	UNSTABLE=true			# build some extra tools
USE_OPENSSL=	yes
SUB_FILES=	pkg-message

MAN1=		airbase-ng.1 aircrack-ng.1 airdecap-ng.1 airdecloak-ng.1 \
		aireplay-ng.1 airodump-ng.1 airserv-ng.1 airtun-ng.1 \
		buddy-ng.1 easside-ng.1 ivstools.1 kstats.1 makeivs-ng.1 \
		packetforge-ng.1 tkiptun-ng.1 wesside-ng.1

PLIST_FILES=	bin/aircrack-ng bin/airdecap-ng bin/airdecloak-ng \
		bin/buddy-ng bin/ivstools bin/kstats bin/makeivs-ng \
		bin/packetforge-ng \
		sbin/airbase-ng sbin/aireplay-ng sbin/airodump-ng \
		sbin/airserv-ng sbin/airtun-ng sbin/easside-ng \
		sbin/tkiptun-ng sbin/wesside-ng

OPTIONS=	SQLITE	"Use SQLite for storing pre-computed key tables" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: missing byteorder.h
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
MAKE_ARGS+=	SQLITE=true
MAN1+=		airolib-ng.1
PLIST_FILES+=	bin/airolib-ng
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

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>

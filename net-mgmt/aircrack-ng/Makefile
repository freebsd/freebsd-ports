# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	aircrack-ng
DISTVERSION=	1.2b2
PORTREVISION=	2
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://download.aircrack-ng.org/ \
		http://bsd-geek.de/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-${DISTVERSION:C/b/-beta/}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	An 802.11 WEP and WPA-PSK keys cracking program

LICENSE=	GPLv2 BSD3CLAUSE APACHE20
LICENSE_COMB=	dual

USES=		gmake dos2unix
DOS2UNIX_FILES=	src/osdep/byteorder.h
MAKE_ARGS+=	unstable=true prefix=${PREFIX}
USE_OPENSSL=	yes
SUB_FILES=	pkg-message

BIN_FILES=	airdecloak-ng buddy-ng aircrack-ng airdecap-ng ivstools \
		makeivs-ng packetforge-ng wpaclean kstats
SBIN_FILES=	airtun-ng besside-ng airbase-ng easside-ng airodump-ng \
		aireplay-ng wesside-ng airserv-ng tkiptun-ng

OPTIONS_DEFINE=	SQLITE
OPTIONS_SUB=	yes
SQLITE_DESC=	Use SQLite for storing pre-computed key tables

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
MAKE_ARGS+=	SQLITE=true
BIN_FILES+=	airolib-ng
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif
.if ${ARCH} == "sparc64" && ${OSVERSION} > 900000
BROKEN=		Does not compile on sparc64-9
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|-I/usr/local|-I${LOCALBASE}|' \
		-e 's|share/\(man/man[1-9]\)|\1|' \
		-e 's|^CC[[:blank:]]*|&?|' \
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
.for f in ${BIN_FILES}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$f
.endfor
.for f in ${SBIN_FILES}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/$f
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:	wooztalk
# Date created:		2008-07-18
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	wooztalk
PORTVERSION=	0.9.9a
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
    		boost_serialization.4:${PORTSDIR}/devel/boost-libs \
    		boost_regex.4:${PORTSDIR}/devel/boost-libs \
    		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		curl.5:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
NO_BUILD=	yes
USE_WX=		2.8
WX_UNICODE=	yes

OPTIONS=	FIREFOX "Firefox extension (required)" On \
		DAILYMOTION "Dailymotion extension" On \
		DEEZER "Deezer extension" On \
		GOOGLEVIDEO "GoogleVideo extension" On \
		IMEEM "Imeem extension" On \
		JIWA "Jiwa extension" On \
		LASTFM "Last.fm extension" On \
		VIMEO "Vimeo extension" On \
		VLC "VLC extension" On \
		YOUTUBE "Youtube extension" On

.include <bsd.port.pre.mk>

.if defined(WITH_FIREFOX)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/firefoxonwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-firefoxonwooztalk
.endif

.if defined(WITH_DAILYMOTION)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/dailymotiononwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-dailymotiononwooztalk
.endif

.if defined(WITH_DEEZER)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/deezeronwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-deezeronwooztalk
.endif

.if defined(WITH_GOOGLEVIDEO)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/googlevideoonwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-googlevideoonwooztalk
.endif

.if defined(WITH_IMEEM)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/imeemonwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-imeemonwooztalk
.endif

.if defined(WITH_JIWA)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/jiwaonwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-jiwaonwooztalk
.endif

.if defined(WITH_LASTFM)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/lastfmonwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-lastfmonwooztalk
.endif

.if defined(WITH_VIMEO)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/vimeoonwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-vimeoonwooztalk
.endif

.if defined(WITH_VLC)
RUN_DEPENDS+=	${LOCALBASE}/share/vlc/http/wooztalk.html:${PORTSDIR}/multimedia/vlconwooztalk
.endif

.if defined(WITH_YOUTUBE)
RUN_DEPENDS+=	${LOCALBASE}/lib/xpi/youtubeonwooztalk@wooztalk.com:${PORTSDIR}/www/xpi-youtubeonwooztalk
.endif

.if ${OSVERSION} < 700000
BROKEN=		run only on 7.x
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

do-install:
	@${MKDIR} ${DATADIR}/img
	@${MKDIR} ${DATADIR}/sounds
	@${MKDIR} ${DATADIR}/resources
	@${MKDIR} ${DATADIR}/resources/en
	@${MKDIR} ${DATADIR}/resources/fr
	@${MKDIR} ${PREFIX}/share/locale/en
	@${MKDIR} ${PREFIX}/share/locale/fr
	@${INSTALL_PROGRAM} ${WRKSRC}/wooztalk ${PREFIX}/bin/wooztalk
	@${INSTALL_DATA} ${WRKSRC}/WoozTalk.ico ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/wooztalk.pem ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/img/*.* ${DATADIR}/img/
	@${INSTALL_DATA} ${WRKSRC}/sounds/*.* ${DATADIR}/sounds/
	@${INSTALL_DATA} ${WRKSRC}/resources/en/wooztalk.po ${PREFIX}/share/locale/en/LC_MESSAGES/wooztalk.po
	@${INSTALL_DATA} ${WRKSRC}/resources/fr/wooztalk.po ${PREFIX}/share/locale/fr/LC_MESSAGES/wooztalk.po
	@${INSTALL_DATA} ${WRKSRC}/resources/en/wooztalk.po ${DATADIR}/resources/en/wooztalk.po
	@${INSTALL_DATA} ${WRKSRC}/resources/fr/wooztalk.po ${DATADIR}/resources/fr/wooztalk.po

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

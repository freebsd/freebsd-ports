# New ports collection makefile for:	wooztalk
# Date created:		2008-07-18
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	wooztalk
PORTVERSION=	0.9.8b
CATEGORIES=	net-im
MASTER_SITES=	http://www.wooztalk.com/common/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
    		boost_serialization.4:${PORTSDIR}/devel/boost \
    		boost_regex.4:${PORTSDIR}/devel/boost \
    		boost_filesystem.4:${PORTSDIR}/devel/boost \
		curl.4:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${LOCALBASE}/lib/xpi/firefoxonwooztalk@kurioos-itech.com:${PORTSDIR}/www/xpi-firefoxonwooztalk

USE_BZIP2=	yes
NO_BUILD=	yes
USE_WX=		2.8
WX_UNICODE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		run only on 7.x
.endif

do-install:
	@${MKDIR} ${DATADIR}/img
	@${MKDIR} ${DATADIR}/sounds
	@${MKDIR} ${PREFIX}/share/locale/en
	@${MKDIR} ${PREFIX}/share/locale/fr
	@${INSTALL_PROGRAM} ${WRKSRC}/wooztalk ${PREFIX}/bin/wooztalk
	@${INSTALL_DATA} ${WRKSRC}/WoozTalk.ico ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/wooztalk.pem ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/img/*.* ${DATADIR}/img/
	@${INSTALL_DATA} ${WRKSRC}/sounds/*.* ${DATADIR}/sounds/
	@${INSTALL_DATA} ${WRKSRC}/resources/en/wooztalk.po ${PREFIX}/share/locale/en/LC_MESSAGES/wooztalk.po
	@${INSTALL_DATA} ${WRKSRC}/resources/fr/wooztalk.po ${PREFIX}/share/locale/fr/LC_MESSAGES/wooztalk.po

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

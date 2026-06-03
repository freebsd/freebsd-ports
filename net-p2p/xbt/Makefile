PORTNAME=	xbt
PORTVERSION=	g20251212
CATEGORIES=	net-p2p

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	High-performance low-overhead BitTorrent tracker
WWW=		https://xbtt.sourceforge.net/tracker.html

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:devel/boost-libs

USES=		compiler:c++17-lang mysql pkgconfig
IGNORE_WITH_MYSQL=	105m 106m 1011m
USE_GITHUB=	yes
GH_ACCOUNT=	OlafvdSpek
GH_TAGNAME=	c5bcfe6

MAKEFILE=	${FILESDIR}/makefile

PLIST_FILES=	bin/${PORTNAME}_tracker \
		@sample\ etc/xbt_tracker.conf.sample \
		${DATADIR_REL}/xbt_tracker.sql

PORTSCOUT=	ignore:1	# plenty of old tags from 2008 and earlier

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME}_tracker \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/Tracker/xbt_tracker.sql \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/Tracker/xbt_tracker.conf.default \
		${STAGEDIR}${PREFIX}/etc/xbt_tracker.conf.sample

.include <bsd.port.mk>

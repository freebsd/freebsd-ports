# New ports collection makefile for:	wmweather+-2.4
# Date created:				11 April 2003
# Whom:				Harald Wille <harald.wille@students.jku.at>
#
# $FreeBSD$

PORTNAME=	wmweather+
PORTVERSION=	2.9
CATEGORIES=	misc windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wmweatherplus

MAINTAINER=	harald.wille@students.jku.at
COMMENT=	Think wmweather with forecasts, weather map, and a sky cond. display

LIB_DEPENDS=	www[a-z]+:${PORTSDIR}/www/libwww \
		xmltok:${PORTSDIR}/www/libwww \
		xmlparse:${PORTSDIR}/www/libwww \
		wraster:${PORTSDIR}/x11-wm/windowmaker \
		pcre:${PORTSDIR}/devel/pcre \
		Xpm:${PORTSDIR}/graphics/xpm \
		tiff:${PORTSDIR}/graphics/tiff \
		Hermes:${PORTSDIR}/graphics/Hermes \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		ungif:${PORTSDIR}/graphics/libungif \
		iconv:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_XPM=	yes

MAN1=		wmweather+.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmweather+ ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmweather+.1 ${PREFIX}/man/man1

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.conf ${EXAMPLESDIR}/example.conf

	@${ECHO} ""
	@${ECHO} "================================================="
	@${ECHO} "Sample configuration file has been copied to"
	@${ECHO} "${EXAMPLESDIR}/example.conf"
	@${ECHO} ""
	@${ECHO} "Please copy it to your homedir into .wmweather+"
	@${ECHO} "as conf and adjust it to your needs!"
	@${ECHO} "================================================="
	@${ECHO} ""

.include <bsd.port.mk>

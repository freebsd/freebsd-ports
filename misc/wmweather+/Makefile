# New ports collection makefile for:	wmweather+-2.4
# Date created:				11 April 2003
# Whom:				Harald Wille <harald.wille@students.jku.at>
#
# $FreeBSD$

PORTNAME=	wmweather+
PORTVERSION=	2.9
PORTREVISION=	4
CATEGORIES=	misc windowmaker geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wmweatherplus

MAINTAINER=	harald.wille@students.jku.at
COMMENT=	Think wmweather with forecasts, weather map, and a sky cond. display

LIB_DEPENDS=	xmlparse:${PORTSDIR}/www/libwww \
		wraster:${PORTSDIR}/x11-wm/windowmaker \
		pcre:${PORTSDIR}/devel/pcre \
		tiff:${PORTSDIR}/graphics/tiff \
		Hermes:${PORTSDIR}/graphics/Hermes \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		ungif:${PORTSDIR}/graphics/libungif

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_XORG=	xpm

CONFIGURE_ARGS+=	--with-libwraster=${X11BASE}

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

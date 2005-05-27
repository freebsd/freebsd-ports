# ex:ts=8
# New ports collection makefile for:	snownews
# Date created:			Nov 3 2003
# Whom:				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	snownews
PORTVERSION=	1.5.6.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://kiza.kcore.de/software/snownews/download/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A text mode RSS newsreader

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes

.if defined(CHARSET)
CONFIGURE_ARGS=	--charset=${CHARSET}
.if ${CHARSET} == "UTF-8"
post-configure:
	@${REINPLACE_CMD} -e 's|ncursesw|ncurses|g' ${WRKSRC}/platform_settings
.endif
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		snownews.1
MANLANG=	"" de nl fr it ru_RU.KOI8-R

pre-everything::
	@${ECHO_MSG} " "
	@${ECHO_MSG} " You can set up CHARSET variable for your localization."
	@${ECHO_MSG} " Example: make CHARSET=ISO-8859-2"
	@${ECHO_MSG} " Default is ISO-8859-1."
	@${ECHO_MSG} " "

post-patch:
	@${REINPLACE_CMD} -e 's|#!/usr/bin/perl|#!${PERL}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS+=|g' ${WRKSRC}/platform_settings
	@${REINPLACE_CMD} -e 's|^PREFIX|#PREFIX|' ${WRKSRC}/platform_settings
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's/ install-locales / /g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/ locales$$//g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>

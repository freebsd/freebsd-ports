# New ports collection makefile for:	kopete
# Date created:		21 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kopete
PORTVERSION=	0.5.1
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1/-1/}

MAINTAINER=	stefan.jahn@nemesis-sektor.de

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,305,306,' \
		${WRKSRC}/kopete/libkopete/ui/appearanceconfig.cpp \
		${WRKSRC}/kopete/libkopete/ui/appearanceconfig.h \
		${WRKSRC}/kopete/libkopete/ui/kopetechatwindow.cpp \
		${WRKSRC}/kopete/libkopete/ui/kopetecontactviewitem.cpp \
		${WRKSRC}/kopete/libkopete/ui/kopetemetacontactlvi.cpp \
		${WRKSRC}/kopete/libkopete/ui/kopetewindow.cpp \
		${WRKSRC}/kopete/libkopete/kopeteprefs.cpp \
		${WRKSRC}/kopete/libkopete/kopeteprefs.h \
		${WRKSRC}/kopete/protocols/icq_new/icqchangestatus.cpp
	${REINPLACE_CMD} -e 's,= 305,= 306,' \
		${WRKSRC}/kopete/protocols/irc/ircmessage.cpp

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>

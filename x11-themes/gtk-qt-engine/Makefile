# New ports collection makefile for:    gtk-qt-engine
# Date created:                         23 February 2004
# Whom:                                 Danny Pansters <danny@ricin.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-qt-engine
PORTVERSION=	0.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.freedesktop.org/Software/gtk-qt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GTK-QT Theme Engine allows GTK2 to use QT widget styles

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
WANT_GNOME=	no
USE_GNOME=	gnomehack gtk20
USE_QT_VER=	3
USE_REINPLACE=	yes

PLIST_SUB=	GTK_VER=2.4.0

PKGMESSAGE=	${WRKDIR}/pkg-message

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/configure

post-install:
	@${ECHO_MSG}
	@${SED} -e "s:/usr/X11R6:${PREFIX}:" ${FILESDIR}/pkg-message.in	\
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>

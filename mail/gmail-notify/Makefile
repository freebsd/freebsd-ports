# New ports collection makefile for:	gmail-notify
# Date created:				07 June 2005
# Whom:					David
#
# $FreeBSD$
#

PORTNAME=	gmail-notify
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	djulien.bsd@gmail.com
COMMENT=	GMail Notifier

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/x11-toolkits/py-gnome-extras:extract

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/${PORTNAME}

EXTRAS_WRKSRC!=	cd ${PORTSDIR}/x11-toolkits/py-gnome-extras && ${MAKE} -V WRKSRC

post-patch:
	${SED} -e 's|@DATADIR@|${DATADIR}|' ${FILESDIR}/gmail-notifier > ${WRKSRC}/gmail-notifier

pre-configure:
	${CP} ${EXTRAS_WRKSRC}/egg/tray/eggtrayicon.[ch] ${EXTRAS_WRKSRC}/egg/tray/trayicon* ${WRKSRC}
	${CP} ${FILESDIR}/config.h ${FILESDIR}/Makefile ${WRKSRC}
	${RM} ${WRKSRC}/pytrayicon.so

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/gmail-notifier ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.py ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.png ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jpg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.so ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/langs.xml ${DATADIR}

.include <bsd.port.post.mk>

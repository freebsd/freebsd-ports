# New ports collection makefile for:	gmail-notify
# Date created:				07 June 2005
# Whom:					David
#
# $FreeBSD$
#

PORTNAME=	gmail-notify
PORTVERSION=	1.6.1.1
PORTREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
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
	${SED} -e 's|@PYTHON_INCLUDEDIR@|${PYTHON_INCLUDEDIR}|' ${FILESDIR}/Makefile.in > ${WRKSRC}/Makefile

pre-configure:
	${CP} ${EXTRAS_WRKSRC}/egg/tray/eggtrayicon.[ch] ${EXTRAS_WRKSRC}/egg/tray/trayicon* ${WRKSRC}
	${CP} ${FILESDIR}/config.h ${WRKSRC}
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

# Created by: David
# $FreeBSD$

PORTNAME=	gmail-notify
PORTVERSION=	1.6.1.1
PORTREVISION=	5
CATEGORIES=	mail python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	GMail Notifier

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/x11-toolkits/py-gnome-extras:extract

USE_GNOME=	pygtk2
USES=		gmake pkgconfig python

WRKSRC=		${WRKDIR}/${PORTNAME}

EXTRAS_DIR=	${PORTSDIR}/x11-toolkits/py-gnome-extras

post-patch:
	${SED} -e 's|@DATADIR@|${DATADIR}|' ${FILESDIR}/gmail-notifier > ${WRKSRC}/gmail-notifier
	${SED} -e 's|@PYTHON_INCLUDEDIR@|${PYTHON_INCLUDEDIR}|' ${FILESDIR}/Makefile.in > ${WRKSRC}/Makefile

pre-build:
	${CP} `${MAKE} -C ${EXTRAS_DIR} -V WRKSRC`/egg/tray/eggtrayicon.[ch] ${WRKSRC}
	${CP} `${MAKE} -C ${EXTRAS_DIR} -V WRKSRC`/egg/tray/trayicon* ${WRKSRC}
	${CP} ${FILESDIR}/config.h ${WRKSRC}
	${RM} ${WRKSRC}/pytrayicon.so

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/gmail-notifier ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.png ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jpg ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.so ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/langs.xml ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

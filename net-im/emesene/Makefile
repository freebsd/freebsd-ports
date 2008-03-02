# New ports collection makefile for:	emesene
# Date created:				31 May 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	emesene
PORTVERSION=	0.20070820
CATEGORIES=	net-im python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-r801

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MSN Messenger client

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GNOME=	pygtk2
REINPLACE_ARGS=	-i ""

DESKTOP_ENTRIES="${PORTNAME}" \
		"${COMMENT}" \
		"${DATADIR}/themes/default/userPanel.png" \
		"${PORTNAME}" \
		"Network;InstantMessaging;GTK;" \
		"false"

post-patch:
	@${CHMOD} a+x ${WRKSRC}/emesene
	@${REINPLACE_CMD} -e \
		's:Controller.py:${DATADIR}/Controller.py:' ${WRKSRC}/emesene
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/${PORTNAME}.sh
	@${ECHO_CMD} 'cd ${DATADIR}&&exec ./${PORTNAME}' >> ${WRKDIR}/${PORTNAME}.sh

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}

do-install:
	@${INSTALL} -d ${DATADIR}/
	@${CP} -R ${WRKSRC}/ ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

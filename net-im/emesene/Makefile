# New ports collection makefile for:	emesene
# Date created:				31 May 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	emesene
PORTVERSION=	1.6.3
PORTREVISION=	2
CATEGORIES=	net-im python
#MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}
MASTER_SITES=	${MASTER_SITE_LOCAL:S,$,acm/${PORTNAME}/,} \
		${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A MSN Messenger client written in python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify
RUN_DEPENDS:=	${BUILD_DEPENDS}

PROJECTHOST=	bsdistfiles
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GNOME=	pygtk2 desktopfileutils
USE_GSTREAMER=	python
INSTALLS_ICONS=	yes
REINPLACE_ARGS=	-i ""

MAN1=		emesene.1

DESKTOP_ENTRIES="${PORTNAME}" \
		"${COMMENT}" \
		"${DATADIR}/themes/default/userPanel.png" \
		"${PORTNAME}" \
		"Network;InstantMessaging;GTK;" \
		"false"

post-extract:
	@cd ${WRKSRC} && \
		${RM} -fr GPL LGPL PSF README pygif pyisf docs && \
			${MV} misc ${WRKDIR} && \
				${MV} po ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/${PORTNAME}

do-build:
	@cd ${WRKSRC} && \
		${PYTHON_CMD} setup.py build_ext -i
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}

	@${ECHO_CMD} "#!/bin/sh" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "cd ${DATADIR} || exit 1" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "exec ${PYTHON_CMD} ./${PORTNAME}" >> ${WRKDIR}/run.sh

pre-install:
	@${RM} -fr ${WRKSRC}/build ${WRKSRC}/libmimic
.	for DIRE in ast dv fil fo gv ku la nb_NO nds oc zh_HK
		@${MKDIR} ${PREFIX}/share/locale/${DIRE}/LC_MESSAGES
.	endfor

do-install:
	@${MKDIR} ${DATADIR}

	cd ${WRKDIR}/po && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/locale/{}" \;
	cd ${WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

	${INSTALL_SCRIPT} ${WRKDIR}/run.sh ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKDIR}/misc/${MAN1} ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/misc/emesene.svg ${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKDIR}/misc/emesene.png ${WRKDIR}/misc/emesene-big.png \
		${PREFIX}/share/pixmaps

post-install:
	-@update-desktop-database

.include <bsd.port.mk>

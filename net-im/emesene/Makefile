# New ports collection makefile for:	emesene
# Date created:				31 May 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	emesene
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A MSN Messenger client writen in python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GNOME=	pygtk2
REINPLACE_ARGS=	-i ""

PLIST=		${WRKDIR}/pkg-plist

DESKTOP_ENTRIES="${PORTNAME}" \
		"${COMMENT}" \
		"${DATADIR}/themes/default/userPanel.png" \
		"${PORTNAME}" \
		"Network;InstantMessaging;GTK;" \
		"false"

post-extract:
	@cd ${WRKSRC} && \
		${RM} -f GPL LGPL README

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/${PORTNAME}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}

	@${ECHO_CMD} "cd ${DATADIR} || exit 1" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "exec ${PYTHON_CMD} ./${PORTNAME}" >> ${WRKDIR}/run.sh

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
		${FIND}  * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}
	@${ECHO_CMD} "bin/${PORTNAME}" >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

	${INSTALL_SCRIPT} ${WRKDIR}/run.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

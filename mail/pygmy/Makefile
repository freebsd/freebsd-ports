# New ports collection makefile for:	pygmy
# Date created:				15 August 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pygmy
PORTVERSION=	0.5.4
CATEGORIES=	mail python gnome
MASTER_SITES=	http://pygmy.sourceforge.net/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome
RUN_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome

USE_PYTHON=	yes

MAKE_ENV=	PYTHON_VERSION="${PYTHON_VERSION}"
ALL_TARGET=	pythonprogs

do-configure:
	@${ECHO} "PYGMY_PREFIX='${PREFIX}/share'" > ${WRKSRC}/prefix.py

do-install:
	${MKDIR} ${PREFIX}/share/pygmy/icons
	${INSTALL_DATA} ${WRKSRC}/*.pyo ${WRKSRC}/*.pyc ${PREFIX}/share/pygmy
	${INSTALL_DATA} ${WRKSRC}/icons/* ${PREFIX}/share/pygmy/icons
	${INSTALL_DATA} ${WRKSRC}/pygmy ${PREFIX}/share/pygmy
	@printf "#!/bin/sh\n${PYTHON_CMD} ${PREFIX}/share/pygmy/pygmy" > \
		${WRKDIR}/pygmy.sh
	${INSTALL_SCRIPT} ${WRKDIR}/pygmy.sh ${PREFIX}/bin/pygmy

.include <bsd.port.mk>

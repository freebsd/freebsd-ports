# New ports collection makefile for:	pygmy
# Date created:				15 August 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pygmy
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	mail python gnome
MASTER_SITES=	http://pygmy.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiny GNOME mail client written in the Python programming language

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		gpg:${PORTSDIR}/security/gnupg

USE_PYTHON=	yes

MAKE_ENV=	PYTHON_VERSION="${PYTHON_VERSION}"
ALL_TARGET=	pythonprogs

do-configure:
	@${ECHO_CMD} "PYGMY_PREFIX='${PREFIX}/share'" > ${WRKSRC}/prefix.py
	@${ECHO_CMD} "PYGMY_ICONDIR='${PREFIX}/share/pygmy/icons'" >> ${WRKSRC}/prefix.py

do-install:
	${MKDIR} ${PREFIX}/share/pygmy/icons
.for ext in py pyc pyo
	${INSTALL_DATA} ${WRKSRC}/*.${ext} ${PREFIX}/share/pygmy
.endfor
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/share/pygmy/icons
	${INSTALL_DATA} ${WRKSRC}/pygmy ${PREFIX}/share/pygmy
	@printf "#!/bin/sh\nexec ${PYTHON_CMD} ${PREFIX}/share/pygmy/pygmy" > \
		${WRKDIR}/pygmy.sh
	${INSTALL_SCRIPT} ${WRKDIR}/pygmy.sh ${PREFIX}/bin/pygmy

.include <bsd.port.mk>

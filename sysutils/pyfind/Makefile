# New ports collection makefile for:	pyfind
# Date created:				5 April 2001
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyfind
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	sysutils python gnome
MASTER_SITES=	http://www.anti-particle.com/downloads/
DISTNAME=	${PORTNAME:S/f/F/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A file-find utility for Gnome loosely modeled after the Windoze utility

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome

USE_PYTHON=	yes

USE_X_PREFIX=	yes
NO_BUILD=	yes

BINDIR=		${PREFIX}/bin
GNOMEBASE=	${PREFIX}/share/gnome
ICONDIR=	${GNOMEBASE}/pixmaps
MYCONFDIR=	${PREFIX}/etc/gnome/config/pyFind
MYDATADIR=	${GNOMEBASE}/pyFind
MYDOCDIR=	${PREFIX}/share/doc/pyFind

do-install:
	${MKDIR} ${MYCONFDIR}
	${MKDIR} ${MYDOCDIR}
	${MKDIR} ${MYDATADIR}/glade
	${MKDIR} ${MYDATADIR}/pixmaps
	${MKDIR} ${MYDATADIR}/pyFind
	${INSTALL_SCRIPT} ${WRKSRC}/pyfind ${MYDATADIR}
	${INSTALL_DATA} ${WRKSRC}/glade/*.glade ${MYDATADIR}/glade
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.png ${MYDATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/pyfind_icon.png ${ICONDIR}
	${INSTALL_DATA} ${WRKSRC}/pyFind/*.py ${MYDATADIR}/pyFind
	${INSTALL_DATA} ${WRKSRC}/pyfind.desktop ${GNOMEBASE}/apps
	${INSTALL_MAN} ${WRKSRC}/doc/* ${MYDOCDIR}
	@printf "#!/bin/sh\n${PYTHON_CMD} ${MYDATADIR}/pyfind" > \
		${WRKDIR}/pyfind.sh
	${INSTALL_SCRIPT} ${WRKDIR}/pyfind.sh ${PREFIX}/bin/pyfind
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MYDATADIR}/pyFind
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${MYDATADIR}/pyFind

.include <bsd.port.mk>

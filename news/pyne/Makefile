# ex:ts=8
# New ports collection makefile for:	pyne
# Date created:			Dec 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pyne
PORTVERSION=	0.6.9
PORTREVISION=	2
CATEGORIES=	news python mail
MASTER_SITES=	http://www.soul-less.pwp.blueyonder.co.uk/pyne/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 offline Newsreader/Emailer

BROKEN=		Configure fails

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/gtkextra/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkextra
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/gtkextra/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkextra

# ugly hack imported from openoffice.
.if !defined(DISPLAY)
BUILD_DEPENDS=	Xvfb:${X_VFBSERVER_PORT}
DISPLAYHACK=localhost:1001
.endif

USE_REINPLACE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
NO_BUILD=	yes
MAKE_ENV=	PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR}"

post-patch:
	@${REINPLACE_CMD} -e "s@[(]PREFIX[)]\/lib@(PYTHON_SITELIBDIR)@g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s@pybins=\(.*\)@pybins=\${PYTHON_VERSION}@" ${WRKSRC}/configure

pre-install:
.if !defined(DISPLAY)
.if exists(${WRKDIR}/.Xvfb.pid)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.endif

	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO_CMD} $$! > \
		${WRKDIR}/.Xvfb.pid
	@${REINPLACE_CMD} -e "s@--compile@--compile --display ${DISPLAYHACK}@" \
		${WRKSRC}/Makefile
.endif

post-install:
.if !defined(DISPLAY)
	@${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} ${WRKDIR}/.Xvfb.pid
.endif

.include <bsd.port.mk>

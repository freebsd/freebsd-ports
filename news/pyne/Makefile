# ex:ts=8
# New ports collection makefile for:	pyne
# Date created:			Dec 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pyne
PORTVERSION=	0.6.9
CATEGORIES=	news python mail
MASTER_SITES=	http://www.soul-less.pwp.blueyonder.co.uk/pyne/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 offline Newsreader/Emailer

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/gtkextra/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkextra
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/gtkextra/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkextra

USE_REINPLACE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
NO_BUILD=	yes
MAKE_ENV=	PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR}"

post-patch:
	@${REINPLACE_CMD} -e "s@[(]PREFIX[)]\/lib@(PYTHON_SITELIBDIR)@g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

# ex:ts=8
# New ports collection makefile for:	gonvert
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gonvert
PORTVERSION=	0.1.5
PORTREVISION=	0
CATEGORIES=	misc python gnome
MASTER_SITES=	http://www.unihedron.com/projects/gonvert/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A conversion utility that allows conversion between many units

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/python,${PYTHON_CMD},g" ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e "s,gnome-config,${GNOME_CONFIG},g ; \
		s,--directory,-d --mode=755,g ; \
		s,install ,install -c ,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>

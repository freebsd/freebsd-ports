# ex:ts=8
# New ports collection makefile for:	gonvert
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gonvert
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	misc python gnome
MASTER_SITES=	http://webhome.idirect.com/~tekatch/anthony/ucu/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GTK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/gtk-1.2/gnome/ui.py:${PORTSDIR}/x11-toolkits/py-gnome

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes

USE_GMAKE=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/python,${PYTHON_CMD},g" ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e "s,gnome-config,${GNOME_CONFIG},g ; \
		s,--directory,-d --mode=755,g ; \
		s,install ,install -c ,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>

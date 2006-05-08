# New ports collection makefile for:	parano
# Date created:		3 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	parano
PORTVERSION=	0.3.0
CATEGORIES=	security
MASTER_SITES=	http://download.berlios.de/%SUBDIR%/ \
		http://download2.berlios.de/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A Gnome program to deal with hashfiles

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	${REINPLACE_CMD} -e 's/$$</$$>/' ${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's,#!.*python,#!${PYTHON_CMD},' ${WRKSRC}/src/parano.py

.include <bsd.port.mk>

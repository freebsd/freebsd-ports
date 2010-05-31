# New ports collection makefile for:	metromap
# Date created:		2005-07-01
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	metromap
PORTVERSION=	0.1.2
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://metromap.antex.ru/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A simple application for finding paths in different subways maps

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,make,${GMAKE},' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${SETENV} python,' ${WRKSRC}/metromap.py

.include <bsd.port.mk>

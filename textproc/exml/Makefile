# New ports collection makefile for:	exml
# Date created:				09 July 2006
# Whom:					Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	exml
PORTVERSION=	20060707
CATEGORIES=	textproc
MASTER_SITES=	http://mbsd.msk.ru/dist/

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	EXML is an abstracted, generalized interface to libxml

LIB_DEPENDS=	ecore.1:${PORTSDIR}/x11/ecore

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	libxml2 gnomehack gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

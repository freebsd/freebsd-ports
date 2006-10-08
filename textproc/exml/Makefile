# New ports collection makefile for:	exml
# Date created:				09 July 2006
# Whom:					Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	exml
PORTVERSION=	20060926
CATEGORIES=	textproc
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	EXML is an abstracted, generalized interface to libxml

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	libxml2 libxslt gnomehack gnometarget pkgconfig
USE_EFL=	ecore
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>

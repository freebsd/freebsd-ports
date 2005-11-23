# New ports collection makefile for:	print/lcdf-typetools
# Date created:				22.11.2005
# Whom:					Ulrich Spoerlein <q@galgenberg.net>
#
# $FreeBSD$
#

PORTNAME=	lcdf-typetools
PORTVERSION=	2.36
CATEGORIES=	print
MASTER_SITES=	http://www.lcdf.org/type/

MAINTAINER=	q@galgenberg.net
COMMENT=	Tools for manipulating Opentype/Type1 PS-Fonts

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX-base

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-kpathsea=${LOCALBASE}

MAN1=	cfftot1.1 mmafm.1 mmpfb.1 otfinfo.1 otftotfm.1 t1dotlessj.1 t1lint.1 \
	t1reencode.1 t1testpage.1

.include <bsd.port.mk>

# New ports collection makefile for:   igal
# Date created:                        14 Aug 2002
# Whom:                                Dylan Carlson  <absinthe@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	igal
PORTVERSION=	1.4
CATEGORIES=	www graphics
MASTER_SITES=	http://www.stanford.edu/~epop/igal/ \
		http://planetmirror.com/pub/igal/

MAINTAINER=	absinthe@pobox.com
COMMENT=	A static html image gallery generator for *nix

USE_REINPLACE=	yes

RUN_DEPENDS=	${LOCALBASE}/bin/cjpeg:${PORTSDIR}/graphics/jpeg \
		${LOCALBASE}/include/Magick++.h:${PORTSDIR}/graphics/ImageMagick

MAN1=	igal.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/Makefile \
		${WRKSRC}/igal

.include <bsd.port.mk>

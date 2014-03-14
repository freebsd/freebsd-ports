# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	gecko-sharp
PORTVERSION=	0.13
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.novell.com/pub/mono/sources/${PORTNAME}2/
DISTNAME=	${PORTNAME}-2.0-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings to embed Mozilla

USE_GECKO=	libxul
USE_GNOME=	gtksharp20
USES=		gmake pkgconfig
LATEST_LINK=	gecko-sharp20
GNU_CONFIGURE=	yes
USE_BZIP2=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>

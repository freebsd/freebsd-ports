# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wsmake
PORTVERSION=	0.7.901
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Software for production and maintenance of web sites

OPTIONS_DEFINE=	DOCS

USES=		gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gwsmake=no --enable-iswmake=no

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INFO=	wsmake iwsmake gwsmake
.else
CONFIGURE_ARGS+=	--enable-docs=no
.endif

.include <bsd.port.mk>

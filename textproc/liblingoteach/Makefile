# $FreeBSD$

PORTNAME=	liblingoteach
PORTVERSION=	0.2.1
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	SF/lingoteach/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing lesson files based on the LingoTeach DTD

USES=		gmake pathfix pkgconfig libtool
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS ZLIB DEBUG
OPTIONS_DEFAULT=	ZLIB

DEBUG_DESC=	Additional debugging information and output

ZLIB_CONFIGURE_WITH=	compression
DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
post-patch:
	@${REINPLACE_CMD} 's|SUBDIRS = src test doc|SUBDIRS = src test|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>

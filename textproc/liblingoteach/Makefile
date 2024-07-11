PORTNAME=	liblingoteach
PORTVERSION=	0.2.1
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	SF/lingoteach/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing lesson files based on the LingoTeach DTD
WWW=		http://www.lingoteach.org

DEPRECATED=	Abandonware, last activity 18+ years ago and fails to build with libxml2 2.13.0 (PR 279705)
EXPIRATION_DATE=2024-07-16

USES=		gmake gnome libtool pathfix pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS ZLIB DEBUG
OPTIONS_DEFAULT=	ZLIB

DEBUG_DESC=	Additional debugging information and output

ZLIB_CONFIGURE_WITH=	compression
DEBUG_CONFIGURE_ENABLE=	debug

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|SUBDIRS = src test doc|SUBDIRS = src test|' \
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>

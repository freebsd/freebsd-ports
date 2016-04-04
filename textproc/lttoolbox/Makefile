# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	lttoolbox
PORTVERSION=	${APVER}.${APREV}
CATEGORIES=	textproc
MASTER_SITES=	SF/apertium/${PORTNAME}/${APVER}

MAINTAINER=	i@levsha.me
COMMENT=	Tool for lexical, morphological analysis and generation of words

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:textproc/libxml2

APVER=	3.3
APREV=	2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig
INSTALL_TARGET=	install-strip

PLIST_SUB+=	APVER="${APVER}"

.include <bsd.port.mk>

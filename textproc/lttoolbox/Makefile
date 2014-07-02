# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	lttoolbox
PORTVERSION=	${APVER}.${APREV}
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/apertium/${PORTNAME}/${APVER}

MAINTAINER=	i@levsha.me
COMMENT=	Tool for lexical, morphological analysis and generation of words

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

APVER=	3.2
APREV=	0

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig

PLIST_SUB+=	APVER="${APVER}"

.include <bsd.port.mk>

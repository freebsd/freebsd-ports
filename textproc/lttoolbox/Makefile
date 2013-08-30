# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	lttoolbox
PORTVERSION=	${APVER}.${APREV}
CATEGORIES=	textproc
MASTER_SITES=	SF/apertium/${PORTNAME}/${APVER}

MAINTAINER=	i@levsha.me
COMMENT=	A tool for lexical, morphological analysis and generation of words

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

APVER=	3.2
APREV=	0

GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes
USES=		pathfix pkgconfig

PLIST_SUB+=	APVER="${APVER}"
MAN1=	lt-comp.1 lt-expand.1 lt-proc.1 lt-tmxcomp.1 lt-tmxproc.1

.include <bsd.port.mk>

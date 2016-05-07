# $FreeBSD$

PORTNAME=	docbook2mdoc
PORTVERSION=	0.0.9
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/docbook2mdoc/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Convert DocBook refentry to mdoc

LICENSE=	ISCL

LIB_DEPENDS=	libexpat.so:textproc/expat2

PLIST_FILES=	bin/docbook2mdoc \
		man/man1/docbook2mdoc.1.gz

USES=	tar:tgz

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

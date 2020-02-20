# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	lttoolbox
PORTVERSION=	${APVER}.${APREV}
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for lexical, morphological analysis and generation of words

LICENSE=	GPLv2

LIB_DEPENDS=	libxml2.so:textproc/libxml2

USES=		autoreconf compiler:c++14-lang libtool pathfix pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

APVER=	3.5
APREV=	1
GH_ACCOUNT=	apertium

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB+=	APVER="${APVER}"

.include <bsd.port.mk>

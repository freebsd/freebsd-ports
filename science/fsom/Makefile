# $FreeBSD$

PORTNAME=	fsom
DISTVERSION=	g20151117
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tiny C library for managing SOM (Self-Organizing Maps) neural networks

LICENSE=	GPLv3

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	56695e1611d824cda97f08e932d25d08419170cd

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/fsom \
		include/fsom/convert.h \
		include/fsom/fsom.h \
		include/fsom/split.h \
		lib/libfsom.a

MAKEFILE=	${FILESDIR}/Makefile

.include <bsd.port.mk>

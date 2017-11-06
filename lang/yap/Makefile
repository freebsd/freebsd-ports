# Created by: Danilo Egea Gondolfo <danilogondolfo@gmail.com>
# $FreeBSD$

PORTNAME=	yap
PORTVERSION=	6.2.2
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	http://www.dcc.fc.up.pt/~vsc/Yap/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High-performance Prolog compiler

LIB_DEPENDS=	libgmp.so:math/gmp

PORTSCOUT=	limit:^6\.2\.
CONFLICTS=	yap-6.3.*

OPTIONS_DEFINE=	DOCS

DOCS_USE=		TEX=formats:build,dvipsk:build
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/texi2html:textproc/texi2html \
			${LOCALBASE}/bin/texi2pdf:print/texinfo
DOCS_INSTALL_TARGET=	install install_docs

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-max-performance \
		--disable-myddas
USES=		gmake localbase readline

DOCSDIR=	${PREFIX}/share/doc/Yap
DATADIR=	${PREFIX}/share/Yap

.include <bsd.port.options.mk>

.if ${ARCH} == i386
# H/absmi.h:77:23: error: global register variables are not supported
USES+=		compiler:gcc-c++11-lib
.endif

post-build:
.if empty(PORT_OPTIONS:MDOCS)
	# prevent the instalation of three docs files
	${REINPLACE_CMD} -e '559,562d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>

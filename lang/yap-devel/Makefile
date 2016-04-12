# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yap
PORTVERSION=	6.3.3
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.dcc.fc.up.pt/~vsc/Yap/
PKGNAMESUFFIX=	-devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High-performance Prolog compiler

LICENSE=	ART20 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgmp.so:math/gmp

CONFLICTS=	yap-6.2.*

OPTIONS_DEFINE=	DOCS MYDDAS
OPTIONS_SUB=	yes
MYDDAS_DESC=	Enable MySQL support

DOCS_USE=		TEX=formats:build,dvipsk:build
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/texi2html:textproc/texi2html \
			${LOCALBASE}/bin/texi2pdf:print/texinfo
DOCS_INSTALL_TARGET=	install install_docs

MYDDAS_LIB_DEPENDS=		libiodbc.so:databases/libiodbc
MYDDAS_CONFIGURE_ENABLE=	myddas myddas-top-level

LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	PKGLDFLAGS="${LDFLAGS}"

STRIP=	#none

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-max-performance --disable-clpbn-bp
USES=		gmake libarchive readline shebangfix
SHEBANG_FILES=	packages/http/examples/demo_inetd
SHEBANG_LANG=	swipl
swipl_OLD_CMD=	/usr/bin/swipl
swipl_CMD=	${LOCALBASE}/bin/swipl # installed by lang/swi-pl
USE_GCC=	any

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SETENV} LC_ALL=en_US.UTF-8 ${TAR} -xf -

DOCSDIR=	${PREFIX}/share/doc/Yap
DATADIR=	${PREFIX}/share/Yap

.include <bsd.port.options.mk>

post-build:
.if empty(PORT_OPTIONS:MDOCS)
	# prevent the installation of docs files
	${REINPLACE_CMD} -e '758,761d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>

# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yap
PORTVERSION=	6.3.3
PORTREVISION=	11
CATEGORIES=	lang
MASTER_SITES=	http://www.dcc.fc.up.pt/~vsc/Yap/
PKGNAMESUFFIX=	-devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High-performance Prolog compiler

BROKEN=		unfetchable

LICENSE=	ART20 LGPL3
LICENSE_COMB=	dual

BROKEN_armv6=		fails to install: tar: Pathname can't be converted from UTF-8 to current locale
BROKEN_armv7=		fails to install: tar: Pathname can't be converted from UTF-8 to current locale
BROKEN_powerpc64=	fails to build: YAP Fatal Error: startup.yss in saved state formatting mismatch in saved space exiting....

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

USES=		gmake libarchive readline shebangfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-max-performance --disable-clpbn-bp
SHEBANG_FILES=	packages/http/examples/demo_inetd
SHEBANG_LANG=	swipl
swipl_OLD_CMD=	/usr/bin/swipl
swipl_CMD=	${LOCALBASE}/bin/swipl # installed by lang/swi-pl

DOCSDIR=	${PREFIX}/share/doc/Yap
DATADIR=	${PREFIX}/share/Yap

post-build-DOCS-off:
	# prevent the installation of docs files
	${REINPLACE_CMD} -e '758,761d' ${WRKSRC}/Makefile

.include <bsd.port.mk>

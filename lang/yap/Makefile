# Created by: Danilo Egea Gondolfo <danilogondolfo@gmail.com>
# $FreeBSD$

PORTNAME=	yap
PORTVERSION=	6.2.2
PORTREVISION=	9
CATEGORIES=	lang
MASTER_SITES=	https://mirrors.dotsrc.org/mirrors/exherbo/	\
		http://ftp.lyx.org/pub/minix/distfiles/backup/	\
		http://tenampak.izt.uam.mx/programas/

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

post-build-DOCS-off:
	# prevent the instalation of three docs files
	${REINPLACE_CMD} -e '559,562d' ${WRKSRC}/Makefile

.include <bsd.port.mk>

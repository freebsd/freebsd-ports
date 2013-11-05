# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yap
PORTVERSION=	6.3.3
CATEGORIES=	lang
MASTER_SITES=	http://www.dcc.fc.up.pt/~vsc/Yap/
PKGNAMESUFFIX=	-devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High-performance Prolog compiler

LICENSE=	ART20 LGPL3
LICENSE_COMB=	dual

CONFLICTS=	yap-6.2.*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	base texmf latex
BUILD_DEPENDS+=	${LOCALBASE}/bin/texi2html:${PORTSDIR}/textproc/texi2html
BUILD_DEPENDS+=	${LOCALBASE}/bin/texi2pdf:${PORTSDIR}/print/texinfo
.endif

STRIP=	#none

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-max-performance
USES=	gmake
USE_GCC=	any

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SETENV} LC_ALL=en_US.UTF-8 ${TAR} -xf -

DOCSDIR=	${PREFIX}/share/doc/Yap
DATADIR=	${PREFIX}/share/Yap

post-build:
.if empty(PORT_OPTIONS:MDOCS)
	# prevent the installation of docs files
	${REINPLACE_CMD} -e '758,761d' ${WRKSRC}/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC} ; ${MAKE} DESTDIR=${STAGEDIR} install_docs)
.endif

.include <bsd.port.mk>

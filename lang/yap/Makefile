# Created by: Danilo Egea Gondolfo <danilogondolfo@gmail.com>
# $FreeBSD$

PORTNAME=	yap
PORTVERSION=	6.2.2
CATEGORIES=	lang
MASTER_SITES=	http://www.dcc.fc.up.pt/~vsc/Yap/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	High-performance Prolog compiler

PORTSCOUT=	limit:^6\.2\.

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	PORTDOCS=""
USE_TEX=	base texmf latex
BUILD_DEPENDS+=	${LOCALBASE}/bin/texi2html:${PORTSDIR}/textproc/texi2html
BUILD_DEPENDS+=	${LOCALBASE}/bin/texi2pdf:${PORTSDIR}/print/texinfo
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-max-performance
USES=	gmake
USE_GCC=	any

DOCSDIR=	${PREFIX}/share/doc/Yap
DATADIR=	${PREFIX}/share/Yap

post-build:
.if empty(PORT_OPTIONS:MDOCS)
	# prevent the instalation of three docs files
	${REINPLACE_CMD} -e '559,562d' ${WRKSRC}/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC} ; ${MAKE} DESTDIR=${STAGEDIR} install_docs)
.endif

.include <bsd.port.mk>

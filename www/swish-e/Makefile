# Created by: Daniel O'Connor <doconnor@gsoft.com.au>
# $FreeBSD$

PORTNAME=	swish-e
PORTVERSION=	2.4.7
PORTREVISION=	4
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/distribution/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple web indexing for humans - enhanced

BROKEN_FreeBSD_12=	fails to compile: zlib.h: conflicting types for 'uncompress2'

USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USES=		gmake libtool perl5 shebangfix
SHEBANG_FILES=	src/swishspider
GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		pkgdatadir="${DATADIR}"
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -E 's/^(install-data-am:) install-docDATA(.*)/\1\2/' \
		${WRKSRC}/Makefile.in
.for p in pod prog-bin conf filter-bin filters html
	@${REINPLACE_CMD} -E 's/^(install-data-am:).*DATA(.*)/\1\2/' \
		${WRKSRC}/${p}/Makefile.in
.endfor
.endif

.include <bsd.port.mk>

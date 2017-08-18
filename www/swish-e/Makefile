# Created by: Daniel O'Connor <doconnor@gsoft.com.au>
# $FreeBSD$

PORTNAME=	swish-e
PORTVERSION=	2.4.7
PORTREVISION=	4
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/distribution/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple web indexing for humans - enhanced

USES=		gmake libtool perl5 shebangfix
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
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
	# Rename uncompress2 to swishe_uncompress2 to fix building with newer zlib which exports
	# its own uncompress2
	${FIND} ${WRKSRC}/src -type f -exec ${REINPLACE_CMD} 's,uncompress2,swishe_uncompress2,g' {} \+

.include <bsd.port.mk>

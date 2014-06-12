# Created by: Daniel O'Connor <doconnor@gsoft.com.au>
# $FreeBSD$

PORTNAME=	swish-e
PORTVERSION=	2.4.7
PORTREVISION=	2
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/distribution/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple web indexing for humans - enhanced

USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USES=		gmake libtool
GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
                pkgdatadir="${DATADIR}"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E 's/^(install-data-am:) install-docDATA(.*)/\1\2/' \
		${WRKSRC}/Makefile.in
.for p in pod prog-bin conf filter-bin filters html
	@${REINPLACE_CMD} -E 's/^(install-data-am:).*DATA(.*)/\1\2/' \
		${WRKSRC}/${p}/Makefile.in
.endfor
.endif

.include <bsd.port.mk>

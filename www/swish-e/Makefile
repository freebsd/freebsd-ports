# New ports collection makefile for:    swish-e
# Date created:         		23 Feb 98
# Whom:              			Daniel O'Connor <doconnor@gsoft.com.au>
#
# $FreeBSD$
#

PORTNAME=	swish-e
PORTVERSION=	2.4.7
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/distribution/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple web indexing for humans - enhanced

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig" \
		pkgdatadir="${DATADIR}"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

MAN1=		SWISH-CONFIG.1 SWISH-FAQ.1 SWISH-LIBRARY.1 SWISH-RUN.1 swish-e.1

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -E 's/^(install-data-am:) install-docDATA(.*)/\1\2/' \
		${WRKSRC}/Makefile.in
.for p in pod prog-bin conf filter-bin filters html
	@${REINPLACE_CMD} -E 's/^(install-data-am:).*DATA(.*)/\1\2/' \
		${WRKSRC}/${p}/Makefile.in
.endfor
.endif

.include <bsd.port.mk>

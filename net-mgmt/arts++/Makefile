PORTNAME=	arts++
PORTVERSION=	1.1.a13
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://distrib-coffee.ipsl.jussieu.fr/pub/linux/momonga/3/SOURCES/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network data storage and analysis library from CAIDA
WWW=		https://catalog.caida.org/software/arts

LICENSE=	LGPL21

USES=		gmake libtool
USE_CXXSTD=	c++98
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/make_pair/std::make_pair/' \
		${WRKSRC}/classes/include/Ipv4PrefixPatricia.hh.in
	@${REINPLACE_CMD} -e 's|@mandir@|$${DESTDIR}@mandir@|g'  \
		-e 's|@bindir@|$${DESTDIR}@bindir@|g'  \
		${WRKSRC}/apps/*/Makefile.in
	@${REINPLACE_CMD} -e 's|@libdir@|$${DESTDIR}@libdir@|g'  \
		-e 's|@includedir@|$${DESTDIR}@includedir@|g'  \
		${WRKSRC}/classes/*/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libArts.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for f in ChangeLog INSTALL WishList
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>

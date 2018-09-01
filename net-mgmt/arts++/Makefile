# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	arts++
PORTVERSION=	1.1.a13
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.caida.org/tools/utilities/arts/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network data storage and analysis library from CAIDA

LICENSE=	LGPL21

USES=		gmake libtool
USE_CXXSTD=	c++98
GNU_CONFIGURE=	yes
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

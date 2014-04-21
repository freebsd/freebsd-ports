# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	arts++
PORTVERSION=	1.1.a13
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.caida.org/tools/utilities/arts/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network data storage and analysis library from CAIDA

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig
	@${REINPLACE_CMD} -e 's/make_pair/std::make_pair/' \
		${WRKSRC}/classes/include/Ipv4PrefixPatricia.hh.in
	@${REINPLACE_CMD} -e 's|@mandir@|$${DESTDIR}@mandir@|g'  \
		-e 's|@bindir@|$${DESTDIR}@bindir@|g'  \
		${WRKSRC}/apps/*/Makefile.in
	@${REINPLACE_CMD} -e 's|@libdir@|$${DESTDIR}@libdir@|g'  \
		-e 's|@includedir@|$${DESTDIR}@includedir@|g'  \
		${WRKSRC}/classes/*/Makefile.in

post-configure:
	@${REINPLACE_CMD} -E -e "s,( gcc\*),\1 | g++\*,g" ${WRKSRC}/libtool

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for f in ChangeLog INSTALL WishList
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/html
.endif

.include <bsd.port.mk>

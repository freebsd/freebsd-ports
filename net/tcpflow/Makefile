# Created by: Jose M. Alcaide <jose@we.lc.ehu.es>
# $FreeBSD$

PORTNAME=	tcpflow
PORTVERSION=	1.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.digitalcorpora.org/downloads/${PORTNAME}/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Program that captures data transmitted as part of TCP connections

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/icl/interval.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/tcpflow man/man1/tcpflow.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == i386 && ! ${CFLAGS:M-march=*}
# Needed for __sync_add_and_fetch_8
CFLAGS+=	-march=i586
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

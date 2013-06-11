# Created by: Jose M. Alcaide <jose@we.lc.ehu.es>
# $FreeBSD$

PORTNAME=	tcpflow
DISTVERSION=	1.4.0b1
CATEGORIES=	net
MASTER_SITES=	http://www.digitalcorpora.org/downloads/${PORTNAME}/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Program that captures data transmitted as part of TCP connections

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/icl/interval.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		tcpflow.1
PLIST_FILES=	bin/tcpflow

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS ChangeLog NEWS README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>

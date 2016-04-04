# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	braa
PORTVERSION=	0.82
CATEGORIES=	net-mgmt
MASTER_SITES=	http://s-tech.elsat.net.pl/braa/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for making SNMP queries

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

USES=		gmake

LDFLAGS+=	-lcompat

PORTDOCS=	README
PLIST_FILES=	bin/braa

OPTIONS_DEFINE=	DOCS

post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e \
		's|CFLAGS =|CFLAGS+=${CFLAGS}|g ; \
		s|LDFLAGS =|LDFLAGS?=${LDFLAGS}|g ; \
		s|strip $$(OUT)||g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

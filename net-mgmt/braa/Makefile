# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	braa
PORTVERSION=	0.82
CATEGORIES=	net-mgmt
MASTER_SITES=	http://s-tech.elsat.net.pl/braa/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for making SNMP queries

LIB_DEPENDS=	netsnmp.30:${PORTSDIR}/net-mgmt/net-snmp

USE_GMAKE=	yes
LDFLAGS+=	-lcompat

PORTDOCS=	README
PLIST_FILES=	bin/braa

NO_STAGE=	yes
post-patch:
.for file in Makefile
	@${REINPLACE_CMD} -e \
		's|CFLAGS =|CFLAGS+=${CFLAGS}|g ; \
		s|LDFLAGS =|LDFLAGS?=${LDFLAGS}|g ; \
		s|strip $$(OUT)||g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	braa
# Date created:				31.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	braa
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://s-tech.elsat.net.pl/braa/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Tool for making SNMP queries

LIB_DEPENDS=	netsnmp.6:${PORTSDIR}/net/net-snmp

USE_SIZE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
LDFLAGS+=	-lcompat

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
.for i in ${PORTNAME}
	${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

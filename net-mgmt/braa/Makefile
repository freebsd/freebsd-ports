# New ports collection makefile for:	braa
# Date created:				31.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	braa
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://s-tech.elsat.net.pl/braa/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for making SNMP queries

LIB_DEPENDS=	netsnmp.9:${PORTSDIR}/net-mgmt/net-snmp

USE_GMAKE=	yes
LDFLAGS+=	-lcompat

PORTDOCS=	README
PLIST_FILES=	bin/braa

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

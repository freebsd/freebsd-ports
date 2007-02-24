# New ports collection makefile for:	iodine
# Date created:				Feb 15 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iodine
PORTVERSION=	0.3.4
CATEGORIES=	net
MASTER_SITES=	http://code.kryo.se/iodine/

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Tunnel IPv4 data through a DNS server

PLIST_FILES=	bin/iodine sbin/iodined

PORTDOCS=	CHANGELOG README TODO

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,^CC =,CC ?=,' -e 's,^CFLAGS =,CFLAGS +=,' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iodine ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/iodined ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

# ex:ts=8
# Ports collection makefile for:  ttlscan
# Date created:                Wed Apr 2, 2003
# Whom:                        Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	ttlscan
PORTVERSION=	0.1.1
CATEGORIES=	net
MASTER_SITES=	http://www.wormulon.net/files/ttlscan/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A tcp based scanner, showing ttl responses

BUILD_DEPENDS=	${LOCALBASE}/include/dnet.h:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/include/libnet.h:${PORTSDIR}/net/libnet

LDFLAGS+=	-lpcap -ldnet

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -D_XOPEN_SOURCE \
	`libnet-config --defines` ${PORTNAME}.c -o ${PORTNAME} `libnet-config --libs` ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

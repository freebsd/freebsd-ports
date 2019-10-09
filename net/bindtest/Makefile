# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	bindtest
PORTVERSION=	1.56
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		ftp://sunsite.cnlab-switch.ch/mirror/kame/misc/ \
		ftp://ftp.pasta.cs.uit.no/pub/IPv6/kame/misc/ \
		ftp://ftp.ipv6.uni-leipzig.de/pub/ftp.kame.net/pub/kame/misc/
DISTNAME=	${PORTNAME}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Test bind() semantics of IPv6 sockets

USES=		tar:tgz

PLIST_FILES=	bin/bindtest bin/bindtest.sh man/man1/bindtest.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bindtest ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/test.sh \
		${STAGEDIR}${PREFIX}/bin/bindtest.sh
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

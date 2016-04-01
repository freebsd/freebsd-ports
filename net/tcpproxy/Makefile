# Created by: Alexander Hausner <alex@hugo.bmg.gv.at>
# $FreeBSD$

PORTNAME=	tcpproxy
PORTVERSION=	1.2
CATEGORIES=	net
MASTER_SITES=	http://www.spreadspace.org/tcpproxy/releases/ \
		http://alex.bmg.gv.at/programs/

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	Simple TCP connection proxy for IPv4 and IPv6

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	ragel:devel/ragel

USES=		gmake
HAS_CONFIGURE=	yes

USERS=	_tcpproxy
GROUPS=	_tcpproxy

USE_RC_SUBR=	tcpproxy

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PLIST_FILES=	bin/tcpproxy etc/tcpproxy_sample.conf \
		man/man8/tcpproxy.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpproxy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}  ${WRKDIR}/${PORTNAME}-${PORTVERSION}/contrib/example.conf ${STAGEDIR}${PREFIX}/etc/tcpproxy_sample.conf
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/tcpproxy.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	tcptestsuite
PORTVERSION=	0.0.2
CATEGORIES=	net ipv6

MAINTAINER=	gnn@freebsd.org
COMMENT=	Network stack test suite

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	packetdrill:net/packetdrill

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-net
GH_PROJECT=	tcp-testsuite
GH_TAGNAME=	dcf5c31

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-all-tests ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "snd-syn socket-api rcv-icmp snippets state-event-engine" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>

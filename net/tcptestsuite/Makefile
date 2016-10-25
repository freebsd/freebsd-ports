# $FreeBSD$

PORTNAME=	tcptestsuite
PORTVERSION=	0.0.1
CATEGORIES=	net ipv6

MAINTAINER=	gnn@freebsd.org
COMMENT=	Network stack test suite

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	packetdrill:net/packetdrill

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-net
GH_PROJECT=	tcp-testsuite
GH_TAGNAME=	94d4ef3

do-build:
	echo "built"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-all-tests ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/tcp-testsuite
.for f in rcv-rst snd-syn socket-api rcv-icmp rcv-syn snippets
	${MKDIR} ${STAGEDIR}${PREFIX}/share/tcp-testsuite/${f}
	@(cd ${WRKSRC}/${f} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${f})
.endfor

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	tcptestsuite
PORTVERSION=	0.0.2
CATEGORIES=	net ipv6
DISTNAME=	${PORTNAME}-dcf5c31

MAINTAINER=	gnn@freebsd.org
COMMENT=	Network stack test suite

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	packetdrill:net/packetdrill

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-net
GH_PROJECT=	tcp-testsuite
GH_TAGNAME=	dcf5c31

do-build:
	echo "built"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-all-tests ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/tcp-testsuite
.for f in snd-syn socket-api rcv-icmp snippets state-event-engine
	${MKDIR} ${STAGEDIR}${PREFIX}/share/tcp-testsuite/${f}
	@(cd ${WRKSRC}/${f} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${f})
.endfor

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	tcptestsuite
DISTVERSION=	g20210304
CATEGORIES=	net

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Network stack test suite

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	packetdrill:net/packetdrill

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-net
GH_PROJECT=	tcp-testsuite
GH_TAGNAME=	d8ab9af

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-all-tests ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/tests/tcptestsuite
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "fast-open snd-syn socket-api rcv-data-segments rcv-icmp snippets state-event-engine" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${FILESDIR}/tcptestsuite_atf_test ${STAGEDIR}${PREFIX}/tests/
	${INSTALL_DATA} ${FILESDIR}/Kyuafile ${STAGEDIR}${PREFIX}/tests/

.include <bsd.port.mk>

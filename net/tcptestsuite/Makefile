# $FreeBSD$

PORTNAME=	tcptestsuite
DISTVERSION=	g20210304
PORTEPOCH=	1
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

_TEST_DIR=	${STAGEDIR}${PREFIX}/tests/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-all-tests ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "fast-open snd-syn socket-api rcv-data-segments rcv-icmp snippets state-event-engine" ${STAGEDIR}${DATADIR})
	${MKDIR} ${_TEST_DIR}
	${INSTALL_SCRIPT} ${FILESDIR}/tcptestsuite_atf_test ${_TEST_DIR}
	${INSTALL_DATA} ${FILESDIR}/Kyuafile ${_TEST_DIR}

.include <bsd.port.mk>

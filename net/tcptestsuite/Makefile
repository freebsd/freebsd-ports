PORTNAME=	tcptestsuite
DISTVERSION=	g20251201
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Network stack test suite

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	packetdrill:net/packetdrill

# Remember to update files/tcptestsuite_atf_test too
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-net
GH_PROJECT=	tcp-testsuite
GH_TAGNAME=	a18ff2a

NO_ARCH=	yes
NO_BUILD=	yes

_TEST_DIR=	${STAGEDIR}${PREFIX}/tests/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-all-tests ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "fast-open snd-syn socket-api rcv-data-segments rcv-icmp snippets state-event-engine tcp-over-udp" ${STAGEDIR}${DATADIR})
	${MKDIR} ${_TEST_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/double-check.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/tcptestsuite_atf_test ${_TEST_DIR}
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${_TEST_DIR}/tcptestsuite_atf_test
	${INSTALL_DATA} ${FILESDIR}/Kyuafile ${_TEST_DIR}

.include <bsd.port.mk>

PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

USE_RC_SUBR=	bitcoind

CMAKE_ARGS=	-DBUILD_DAEMON=ON \
		-DBUILD_CLI=OFF \
		-DBUILD_GUI=OFF \
		-DBUILD_SHARED_LIBS=OFF \
		-DBUILD_TX=OFF \
		-DBUILD_UTIL=OFF \
		-DBUILD_WALLET_TOOL=OFF

MASTERDIR=	${.CURDIR}/../bitcoin

USERS=		bitcoin
GROUPS=		bitcoin

PLIST_FILES=	"@sample %%ETCDIR%%.conf.sample" \
		bin/bitcoind \
		share/man/man1/bitcoind.1.gz

OPTIONS_DEFINE=		DEBUG HARDENING TESTS WALLET ZMQ
OPTIONS_DEFAULT=	HARDENING WALLET ZMQ

post-install:
	${INSTALL_DATA} ${FILESDIR}/bitcoin.conf ${STAGEDIR}${PREFIX}/etc/bitcoin.conf.sample

.include "${MASTERDIR}/Makefile"

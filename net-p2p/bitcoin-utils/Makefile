PKGNAMESUFFIX=	-utils

COMMENT=	Virtual Peer-to-Peer Currency (CLI and Utilities)

SLAVE_PORT=	yes

CMAKE_ARGS=	-DBUILD_CLI=ON \
		-DBUILD_TX=ON \
		-DBUILD_UTIL=ON \
		-DBUILD_DAEMON=OFF \
		-DBUILD_GUI=OFF \
		-DBUILD_SHARED_LIBS=OFF

MASTERDIR=	${.CURDIR}/../bitcoin

PLIST_FILES=	bin/bitcoin-cli \
		bin/bitcoin-tx \
		bin/bitcoin-util \
		share/man/man1/bitcoin-cli.1.gz \
		share/man/man1/bitcoin-tx.1.gz \
		share/man/man1/bitcoin-util.1.gz

OPTIONS_DEFINE=		DEBUG HARDENING TESTS WALLET
OPTIONS_DEFAULT=	HARDENING TESTS WALLET

WALLET_CMAKE_BOOL+=	ENABLE_WALLET_TOOL
WALLET_PLIST_FILES+=	bin/bitcoin-wallet \
			share/man/man1/bitcoin-wallet.1.gz

.include "${MASTERDIR}/Makefile"

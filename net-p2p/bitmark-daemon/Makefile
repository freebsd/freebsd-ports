PKGNAMESUFFIX=	-daemon

COMMENT=	Bitmark distributed property system daemon

CONFLICTS=	bitmark

DISTINFO_FILE=	${.CURDIR}/distinfo

OPTIONS_SLAVE=		DAEMON
OPTIONS_EXCLUDE=	CLI DUMPER RECORDER

MASTERDIR=	${.CURDIR}/../../net-p2p/bitmark

.include "${MASTERDIR}/Makefile"

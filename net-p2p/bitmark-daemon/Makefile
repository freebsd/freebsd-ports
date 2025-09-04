PORTREVISION=	6
PKGNAMESUFFIX=	-daemon

COMMENT=	Bitmark distributed property system daemon

# license section (for portlint)

CONFLICTS=	bitmark

DISTINFO_FILE=	${.CURDIR}/distinfo

OPTIONS_SLAVE=		DAEMON
OPTIONS_EXCLUDE=	CLI DUMPER RECORDER

MASTERDIR=	${.CURDIR}/../../net-p2p/bitmark

.include "${MASTERDIR}/Makefile"

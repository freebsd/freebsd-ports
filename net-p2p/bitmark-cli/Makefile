PORTREVISION=	5
PKGNAMESUFFIX=	-cli

COMMENT=	Bitmark distributed property system cli

# license section (for portlint)

CONFLICTS=	bitmark

DISTINFO_FILE=	${.CURDIR}/distinfo

OPTIONS_SLAVE=		CLI
OPTIONS_EXCLUDE=	DAEMON DUMPER RECORDER

MASTERDIR=	${.CURDIR}/../../net-p2p/bitmark

.include "${MASTERDIR}/Makefile"

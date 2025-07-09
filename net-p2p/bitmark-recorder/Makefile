PORTREVISION=	4
PKGNAMESUFFIX=	-recorder

COMMENT=	Bitmark distributed property system recorder

# license section (for portlint)

CONFLICTS=	bitmark

DISTINFO_FILE=	${.CURDIR}/distinfo

OPTIONS_SLAVE=		RECORDER
OPTIONS_EXCLUDE=	CLI DAEMON DUMPER

MASTERDIR=	${.CURDIR}/../../net-p2p/bitmark

.include "${MASTERDIR}/Makefile"

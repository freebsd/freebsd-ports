MASTERDIR=	${.CURDIR}/../bitmark
PKGNAMESUFFIX=	-recorder

COMMENT=	Bitmark distributed property system recorder

CONFLICTS?=	bitmark

OPTIONS_EXCLUDE=	CLI DAEMON DUMPER
OPTIONS_DEFAULT=	RECORDER

_SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"

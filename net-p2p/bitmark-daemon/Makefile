MASTERDIR=	${.CURDIR}/../bitmark
PKGNAMESUFFIX=	-daemon

COMMENT=	Bitmark distributed property system daemon

CONFLICTS?=	bitmark

OPTIONS_EXCLUDE=	CLI DUMPER RECORDER
OPTIONS_DEFAULT=	DAEMON

_SLAVE_PORT=	yes

.include "${MASTERDIR}/Makefile"

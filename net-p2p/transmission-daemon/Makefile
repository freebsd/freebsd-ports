PKGNAMESUFFIX=	-daemon
PORTREVISION=	4

USES=		ssl
NLS_USES=	gettext-runtime:run

USERS=		transmission
GROUPS=		transmission
USE_RC_SUBR=	transmission

MASTERDIR=	${.CURDIR}/../transmission-cli
DESCR=		${.CURDIR}/pkg-descr
PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${.CURDIR}/pkg-plist

SLAVEPORT=	daemon

.include "${MASTERDIR}/Makefile"

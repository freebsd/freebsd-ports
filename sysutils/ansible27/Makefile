PORTVERSION=	2.7.18
PKGNAMESUFFIX=	27

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

USES=		cpe python:3.6+
EXTRA_PATCHES=	${FILESDIR}/extra-patch-sesu \
		${FILESDIR}/extra-patch-27

.include "${MASTERDIR}/Makefile"

PORTVERSION=	2.7.18
PORTREVISION=	3
PKGNAMESUFFIX=	27

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

DEPRECATED=	Upstream support ended; consider upgrading to sysutils/ansible
EXPIRATION_DATE=2021-05-20

USES=		cpe python:3.6+
EXTRA_PATCHES=	${FILESDIR}/extra-patch-sesu \
		${FILESDIR}/extra-patch-27

.include "${MASTERDIR}/Makefile"

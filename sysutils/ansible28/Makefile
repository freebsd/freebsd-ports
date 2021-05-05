PORTVERSION=	2.8.20
PORTREVISION=	1
PKGNAMESUFFIX=	28

CONFLICTS=	ansible-* \
		ansible1-* \
		ansible23-* \
		ansible24-* \
		ansible25-* \
		ansible26-* \
		ansible27-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

DEPRECATED=	Upstream support ended; consider upgrading to sysutils/ansible

USES=		cpe python:3.6+
EXTRA_PATCHES=

.include "${MASTERDIR}/Makefile"

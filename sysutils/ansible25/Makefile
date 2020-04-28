# $FreeBSD$

PORTVERSION=	2.5.15
PORTREVISION=	3
PKGNAMESUFFIX=	25

CONFLICTS=	ansible-* \
		ansible1-* \
		ansible23-* \
		ansible24-* \
		ansible26-* \
		ansible27-* \
		ansible28-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

DEPRECATED=	Upstream support ended. Consider upgrading to sysutils/ansible
EXPIRATION_DATE=2020-05-31

USES=		cpe python
EXTRA_PATCHES=

.include "${MASTERDIR}/Makefile"

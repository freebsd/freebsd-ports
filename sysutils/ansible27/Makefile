# $FreeBSD$

PORTVERSION=	2.7.15
PKGNAMESUFFIX=	27

CONFLICTS=	ansible-* \
		ansible1-* \
		ansible23-* \
		ansible24-* \
		ansible25-* \
		ansible26-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

EXTRA_PATCHES=	${FILESDIR}/extra-patch-sesu

.include "${MASTERDIR}/Makefile"

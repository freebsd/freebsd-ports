# $FreeBSD$

PORTVERSION=	2.6.20
PKGNAMESUFFIX=	26

CONFLICTS=	ansible-* \
		ansible1-* \
		ansible23-* \
		ansible24-* \
		ansible25-* \
		ansible27-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

EXTRA_PATCHES=	${FILESDIR}/extra-patch-sesu

.include "${MASTERDIR}/Makefile"

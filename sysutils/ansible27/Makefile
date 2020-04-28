# $FreeBSD$

PORTVERSION=	2.7.17
PORTREVISION=	1
PKGNAMESUFFIX=	27

CONFLICTS=	ansible-* \
		ansible1-* \
		ansible23-* \
		ansible24-* \
		ansible25-* \
		ansible26-* \
		ansible28-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

USES=		cpe python
EXTRA_PATCHES=	${FILESDIR}/extra-patch-sesu \
		${FILESDIR}/extra-patch-27

.include "${MASTERDIR}/Makefile"

# Created by: Alexander Sulfrian <alexander@sulfrian.net>
# $FreeBSD$

PKGNAMESUFFIX=	-client

CONFLICTS=	nsca-client-2.* nsca27-client-2.*
PLIST=	${.CURDIR}/pkg-plist

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTEXAMPLES=	README acknowledge debug_server disable_notifications \
		downtime enable_notifications invoke_check

MASTERDIR=	${.CURDIR}/../nsca-ng

.include "${MASTERDIR}/Makefile"

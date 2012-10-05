# $FreeBSD$

MASTERDIR=		${.CURDIR}/../apache22

MAINTAINER=		apache@FreeBSD.org

WITH_MPM=		event

LATEST_LINK=		apache22-${WITH_MPM}-mpm
DESCR=			${.CURDIR}/pkg-descr

PORT_OPTIONS+=		CGID
OPTIONS_EXCLUDE=	CGI
OPTIONS_UNSET+=		CGI

.include "${MASTERDIR}/Makefile"

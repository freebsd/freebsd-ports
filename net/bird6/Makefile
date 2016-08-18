# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bird6
COMMENT=	Dynamic IP routing daemon (IPv6 version)
DISTNAME=	bird-${PORTVERSION}

MASTERDIR=	${.CURDIR}/../bird

USE_RC_SUBR=	${PORTNAME}

PLIST_SUB=	VER="6"

CONFIGURE_ARGS=	--enable-ipv6

.include "${MASTERDIR}/Makefile"

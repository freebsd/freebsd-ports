# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 Stefan `Sec` Zehl <sec@42.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX =	-ssl

COMMENT=	A non-graphical, text-based World-Wide Web client with SSL support

MASTERDIR=	${.CURDIR}/../lynx
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"

CONFIGURE_ARGS+= --with-ssl

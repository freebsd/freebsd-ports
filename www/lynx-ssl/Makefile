# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 Stefan `Sec` Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTCOMMENT=	A non-graphical, text-based https-enabled World-Wide Web client

PKGNAMESUFFIX =	-ssl

MASTERDIR=	${.CURDIR}/../lynx
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"

CONFIGURE_ARGS+= --with-ssl

# New ports collection makefile for:    lynx
# Date created:         15 Dec 1994
# Whom:                 Stefan `Sec` Zehl <sec@42.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-ssl

COMMENT=	A non-graphical, text-based World-Wide Web client with SSL support

MASTERDIR=	${.CURDIR}/../lynx
DESCR=		${.CURDIR}/pkg-descr

CONFIGURE_ARGS+=	--with-ssl

CONFLICTS=	lynx-2* lynx-current*

.include "${MASTERDIR}/Makefile"

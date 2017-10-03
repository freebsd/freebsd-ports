# Created by: Jeremie Le Hen <jlh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdrcmds
PORTVERSION=	20171003
CATEGORIES=	net

USE_GITHUB=	yes
GH_ACCOUNT=	jlehen

MAINTAINER=	jlh@FreeBSD.org
COMMENT=	FreeBSD rcmds (rcp/rlogin/rlogind/rsh/rshd/ruptime/rwho/rwhod)

LICENSE=	BSD3CLAUSE

USES=		uidfix

MAKE_ARGS+=		BINOWN=${BINOWN} BINMODE=${BINMODE}
MAKE_ENV+=		NO_WERROR=1

OPTIONS_DEFINE=		IPV6 LIBBLACKLIST
OPTIONS_DEFAULT=	LIBBLACKLIST
.if !exists(/usr/include/blacklist.h)
OPTIONS_EXCLUDE=	LIBBLACKLIST
.endif

IPV6_MAKE_ARGS=		USE_IPV6=yes

LIBBLACKLIST_DESC=	libblacklist(3) support for rlogind(8) and rshd(8)
LIBBLACKLIST_MAKE_ARGS=	USE_LIBBLACKLIST=yes

.include <bsd.port.mk>

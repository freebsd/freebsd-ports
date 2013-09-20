# Created by: mike@binghamton.edu
# $FreeBSD$

PORTNAME=	tf
PORTVERSION=	5.0b8
CATEGORIES=	net games
MASTER_SITES=	SF/tinyfugue/tinyfugue/5.0%20beta%208
DISTVERSION=	${PORTVERSION:S/.//}
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A popular programmable MUD client, with macro support and more

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-manpage --enable-version --enable-symlink --datadir=${PREFIX}/lib

PLIST_SUB=	DISTNAME=${DISTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>

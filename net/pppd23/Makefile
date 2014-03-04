# Created by: netch@netch.kiev.ua
# $FreeBSD$

PORTNAME=	pppd
PORTVERSION=	2.3.11
CATEGORIES=	net
MASTER_SITES=	http://samba.anu.edu.au/ftp/ppp/
DISTNAME=	ppp-${PORTVERSION}

MAINTAINER=	netch@netch.kiev.ua
COMMENT=	PPP daemon which uses ppp line discipline

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-no-logf

GNU_CONFIGURE=	yes
MAN8=		pppd.8 pppstats.8 chat.8
MANCOMPRESSED=	yes

NO_STAGE=	yes
IGNORE=		depends on PPPDISC, which is no longer available
DEPRECATED=	Depends on PPPDISC
EXPIRATION_DATE=	2014-03-14

.include <bsd.port.mk>

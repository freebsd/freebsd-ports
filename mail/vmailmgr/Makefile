# New ports collection makefile for:	vmailmgr
# Date created:			24 October 2007
# Whom:				Mij <mij@bitchx.it>
#
# $FreeBSD$
#

PORTNAME=	vmailmgr
PORTVERSION=	0.97
CATEGORIES=	mail
MASTER_SITES=	http://www.vmailmgr.org/current/	\
		http://mirrors.dataloss.nl/vmailmgr.org/current/

MAINTAINER=	mij@bitchx.it
COMMENT=	Virtual domain manager for qmail

MAN1=	checkvpw.1 vauthenticate.1 dumpvuser.1 \
	listvdomain.1 vadduser.1 vchattr.1 vchforwards.1 \
	vdeliver.1 vdeluser.1 vpasswd.1 vpasswds.1 vrehash.1 \
	vsetup.1 vupgrade.1

MAN7=	vmailmgr.7
MAN8=	vmailmgrd.8

USE_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
AUTOMAKE_ARGS+=	--add-missing -Wno-portability
USE_AUTOTOOLS=	aclocal:110 autoconf:261 automake:110

.include <bsd.port.pre.mk>

.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif

.include <bsd.port.post.mk>

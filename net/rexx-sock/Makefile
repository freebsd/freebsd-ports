# ex:ts=8
# Ports collection makefile for:	rexx-sock
# Date created:			Nov 11, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	sock
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rxsock
PKGNAMEPREFIX=	rexx-
DISTNAME=	RxSock-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A function package for Rexx programmers to create sockets

BUILD_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina
RUN_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rexx=regina
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
DATADIR=	${PREFIX}/share/rx${PORTNAME}

post-extract:
	@${CHMOD} +x ${WRKSRC}/install-sh

.include <bsd.port.mk>

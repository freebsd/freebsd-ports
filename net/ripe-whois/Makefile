# New ports collection makefile for:	ripe-whois
# Date created:		18th February 2004
# Whom:			Lars Erik Gullerud <lerik@nolink.net>
#
# $FreeBSD$
#

PORTNAME=	ripe-whois
PORTVERSION=	3.1.1v6
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.ripe.net/tools/

MAINTAINER=	lerik@nolink.net
COMMENT=	The RIPE whois client version 3

USE_PERL5_BUILD=	yes

WRKSRC=		${WRKDIR}/whois-${PORTVERSION}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		whois3.1
PLIST_FILES=	bin/whois3

.include <bsd.port.mk>

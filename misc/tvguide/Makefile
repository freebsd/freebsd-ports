# New ports collection makefile for:	tvguide
# Date created:			19 November 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	tvguide
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.cherrynebula.net/downloads/

MAINTAINER=	dburr@FreeBSD.ORG
COMMENT=	Perl script to pretty-print TV Guide listings from www.tvguide.com

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

NO_BUILD=	YES
PLIST_FILES=	bin/tvguide

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tvguide ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

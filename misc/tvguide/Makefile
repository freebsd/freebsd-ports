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
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script to pretty-print TV Guide listings from www.tvguide.com

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

BROKEN=		"Unfetchable"
DEPRECATED=	Disappeared off the net
EXPIRATION_DATE=2006-01-26

NO_BUILD=	YES
PLIST_FILES=	bin/tvguide

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tvguide ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

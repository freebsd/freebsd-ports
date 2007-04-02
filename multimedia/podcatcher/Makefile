# ex:ts=8
# Ports collection makefile for:	podcatcher
# Date created:			Sep 5, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	podcatcher
PORTVERSION=	1.3.5
CATEGORIES=	multimedia ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Podcast client for the command line

USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

PLIST_FILES=	bin/podcatcher

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>

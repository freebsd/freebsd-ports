# ex:ts=8
# Ports collection makefile for:	script4rss
# Date created:			Aug 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	script4rss
PORTVERSION=	0.4b
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easily create scripts to convert HTML pages to RSS feeds

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,#!/usr/bin/perl,#!${SETENV} perl," ${WRKSRC}/script4rss.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/script4rss.pl ${PREFIX}/bin/script4rss
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

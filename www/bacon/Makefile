# New ports collection makefile for:   bacon
# Date created:        9 September 1999
# Whom:                Justin Robinson <jmrobins@samurai.ruin.org>
#
# $FreeBSD$
#

PORTNAME=	bacon
PORTVERSION=	1.071999
CATEGORIES=	www
MASTER_SITES=	ftp://samurai.ruin.org/pub/All/

MAINTAINER=	jmrobins@samurai.ruin.org

USE_PERL5=	YES

DIST=		bacon.pl

do-build:
		@cd ${WRKSRC}; ${MV} ${DIST} ${DIST}.orig; \
		${SED} -e 's;^#! */usr/local/bin/perl *;#!${PERL5};' \
			${DIST}.orig > ${DIST}

do-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/bacon.pl ${PREFIX}/www/cgi-bin/bacon.pl

post-install:
	${MKDIR} ${PREFIX}/share/doc/bacon/
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/bacon/INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

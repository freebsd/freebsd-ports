# New ports collection makefile for:	cgi-lib.pl
# Date created:		23 June 2002
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	cgi-lib_pl
PORTVERSION=	2.18
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sada
DISTNAME=	cgi-lib.pl-${PORTVERSION}
EXTRACT_SUFX=	.gz

MAINTAINER=	sada@FreeBSD.org
COMMENT=	De facto standard library for creating CGI in perl

USE_PERL5=	YES
NO_BUILD=	YES
NO_WRKSUBDIR=	YES
PLIST_FILES=	%%SITE_PERL%%/cgi-lib.pl
EXTRACT_AFTER_ARGS=	> cgi-lib.pl

INSTALL_BASE=	lib/perl5/site_perl/${PERL_VER}
INSTALL_DIR=	${PREFIX}/${INSTALL_BASE}

do-install:
	-${MKDIR} ${INSTALL_DIR}
	${INSTALL_DATA} ${WRKDIR}/cgi-lib.pl ${INSTALL_DIR}

.include <bsd.port.mk>

# New ports collection makefile for:	fxhtml
# Date created:		21 August 1994
# Whom:			Trefor S. <trefor@flevel.co.uk>
#
# $FreeBSD$
#

PORTNAME=	fxhtml
PORTVERSION=	1.6.7
CATEGORIES=	www
# mastersite is long gone as of October 2003
MASTER_SITES=	# ftp://ftp.flevel.co.uk/pub/fxhtml/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server side extension to HTML eliminating the need for CGI scripts

pre-install:
	${MKDIR} ${PREFIX}/www/cgi-bin ${PREFIX}/www/data

.include <bsd.port.mk>

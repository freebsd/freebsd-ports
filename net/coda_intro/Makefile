# New ports collection makefile for:	coda
# Date created:				19 June 1998
# Whom:					Robert V. Baron <rvb@cs.cmu.edu>
#
# $FreeBSD$
#

PORTNAME=	coda-intro
PORTVERSION=	4.6.6.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
DISTNAME=	coda-intro-4.6.6
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

do-build:
	@${ECHO} "These are simple text files.

do-install:
	@${ECHO} "We will copy the files to ${PREFIX}/share/doc/coda-intro"
	cd ${WRKSRC}; tar --create --file - --exclude \*NetBSD --exclude CVS doc | (cd ${PREFIX}/share; tar xvf -)

.include <bsd.port.mk>

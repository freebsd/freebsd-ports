# New ports collection makefile for:    portcheckout
# Version required:     1.0
# Date created:         1 November 1998
# Whom:                 wosch
#
# $Id: Makefile,v 1.3 1998/11/22 03:52:56 kuriyama Exp $
#

DISTNAME=       portcheckout-1.0
CATEGORIES=	devel
MASTER_SITES=   http://www.freebsd.org/~wosch/src/

MAINTAINER=     wosch@FreeBSD.org

USE_PERL5=      yes
MAN1=		portcheckout.1
MANCOMPRESSED=	maybe

post-patch:
	perl -pi -e 's^\#\!/usr/local/bin/perl^#!${PERL5}^' ${WRKSRC}/portcheckout.pl

.include <bsd.port.mk>

# New ports collection makefile for:    portcheckout
# Date created:         1 November 1998
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	portcheckout
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://wolfram.schneider.org/src/

MAINTAINER=	wosch@FreeBSD.org
COMMENT=	Checkout and build ports and all depending ports

USE_PERL5=	yes
MAN1=		portcheckout.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/portcheckout

post-patch:
	${PERL} -pi -e 's^\#\!${PREFIX}/bin/perl^#!${PERL5}^' ${WRKSRC}/portcheckout.pl

.include <bsd.port.mk>

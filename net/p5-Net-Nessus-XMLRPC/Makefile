# ports collection makefile for:	perl extension for connectiong to a Nessus server
# Date created:				25 January 2011
# Whom:					Paul Schmehl <pauls@utdallas.edu>
#
# $FreeBSD$
#

PORTNAME=	Net-Nessus-XMLRPC
PORTVERSION=	0.30
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/K/KO/KOST
PKGNAMEPREFIX=	p5-

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Perl5 interface for communication with Nessus scanner over XMLRPC

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
PERL_CONFIGURE=	yes

MAN3=		Net::Nessus::XMLRPC.3

.include <bsd.port.mk>

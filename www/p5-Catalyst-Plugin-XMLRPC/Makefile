# New ports collection makefile for:	www/p5-Catalyst-Plugin-XMLRPC
# Date created:				2 Dec 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-XMLRPC
PORTVERSION=	1.0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Dispatch XMLRPC methods with Catalyst

BUILD_DEPENDS=	p5-Catalyst>=5.64:${PORTSDIR}/www/p5-Catalyst \
		p5-RPC-XML>=0:${PORTSDIR}/net/p5-RPC-XML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::XMLRPC.3 \
		Catalyst::Plugin::XMLRPC::DispatchType::XMLRPC.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>

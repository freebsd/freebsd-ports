# New ports collection makefile for:	www/p5-Catalyst-Plugin-XMLRPC
# Date created:				2 Dec 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-XMLRPC
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	Dispatch XMLRPC with Catalyst

BUILD_DEPENDS=	p5-Catalyst>=5.01:${PORTSDIR}/www/p5-Catalyst \
		p5-RPC-XML>=0.45:${PORTSDIR}/net/p5-RPC-XML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::XMLRPC.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>

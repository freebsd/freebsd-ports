# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-File
# Date created:				16 Nov 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-File
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/E/ES/ESSKAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	File storage backend for session data

BUILD_DEPENDS=	p5-Catalyst>=5.0:${PORTSDIR}/www/p5-Catalyst \
		p5-Cache-Cache>=1.02:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Catalyst-Plugin-Session>=0.01:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Class-Accessor>=0.22:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0.04:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::Session::Store::File.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>

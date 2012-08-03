# New ports collection makefile for:	WWW::Mechanize::Cached
# Date created:		31 Aug 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize-Cached
PORTVERSION=	1.41
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to cache response to be polite

RUN_DEPENDS=	\
	p5-Cache-Cache>=1.02:${PORTSDIR}/devel/p5-Cache-Cache \
	p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
	p5-Devel-SimpleTrace>0:${PORTSDIR}/devel/p5-Devel-SimpleTrace \
	p5-Find-Lib>0:${PORTSDIR}/devel/p5-Find-Lib \
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-WWW-Mechanize>0:${PORTSDIR}/www/p5-WWW-Mechanize \
	p5-Storable>=2.21:${PORTSDIR}/devel/p5-Storable
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Warn>0:${PORTSDIR}/devel/p5-Test-Warn

PERL_CONFIGURE=	yes

MAN3=	WWW::Mechanize::Cached.3

.include <bsd.port.mk>

# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	Test-URI
PORTVERSION=	1.08
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Perl module for check URI

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI	\
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI	\
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

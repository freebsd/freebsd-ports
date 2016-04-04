# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-View-XML-Feed
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl extension for Catalyst view for RSS, Atom, or other XML feeds

BUILD_DEPENDS=	p5-Catalyst-Runtime>0:www/p5-Catalyst-Runtime \
		p5-XML-Feed>=0:textproc/p5-XML-Feed \
		p5-TimeDate>=0:devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

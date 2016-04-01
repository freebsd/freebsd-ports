# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-FreshBooks-API
PORTVERSION=	0.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy OO access to the FreshBooks.com API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0.09:devel/p5-B-Hooks-EndOfScope \
		p5-Clone>=0:devel/p5-Clone \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-Moose>=0:devel/p5-Moose \
		p5-Net-OAuth-Simple>=0:net/p5-Net-OAuth-Simple \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-URI>=0:net/p5-URI \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww \
		p5-namespace-autoclean>=0.11:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Sub-Override>=0:devel/p5-Sub-Override \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize>=0:devel/p5-Test-WWW-Mechanize \
		p5-Test-XML>=0:devel/p5-Test-XML

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>

# Created by: aaron@FreeBSD.org
# $FreeBSD$

PORTNAME=	weblint++
PORTVERSION=	1.15
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BDFOY

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML validator and sanity checker

BUILD_DEPENDS=	p5-ConfigReader-Simple>=1.15:devel/p5-ConfigReader-Simple \
		p5-File-Find-Rule>0:devel/p5-File-Find-Rule \
		p5-HTML-Lint>0:www/p5-HTML-Lint \
		p5-HTML-SimpleLinkExtor>0:www/p5-HTML-SimpleLinkExtor \
		p5-libwww>0:www/p5-libwww \
		p5-HTTP-SimpleLinkChecker>0:www/p5-HTTP-SimpleLinkChecker \
		p5-HTTP-Size>=0.04:www/p5-HTTP-Size \
		p5-Mail-Sendmail>0:mail/p5-Mail-Sendmail \
		p5-Text-Diff>0:textproc/p5-Text-Diff \
		p5-Text-Template>0:textproc/p5-Text-Template \
		p5-URI>0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Manifest>0.91:devel/p5-Test-Manifest \
		p5-Test-Pod>=0.90:devel/p5-Test-Pod \
		p5-Test-File>0:devel/p5-Test-File

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

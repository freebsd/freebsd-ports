# $FreeBSD$

PORTNAME=	HTML-Shakan
PORTVERSION=	2.00
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SONGMU
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of form html generator/validator

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Email-Valid-Loose>=0.05:mail/p5-Email-Valid-Loose \
	p5-FormValidator-Lite>=0.24:textproc/p5-FormValidator-Lite \
	p5-List-MoreUtils>=0.22:lang/p5-List-MoreUtils \
	p5-Mouse>=0.90,1:devel/p5-Mouse
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Lingua-JA-Regular-Unicode>0:japanese/p5-Lingua-JA-Regular-Unicode \
	p5-DateTime>0:devel/p5-DateTime \
	p5-DateTime-Format-HTTP>0:devel/p5-DateTime-Format-HTTP \
	p5-Data-Model>0:devel/p5-Data-Model \
	p5-DBIx-Skinny>0:databases/p5-DBIx-Skinny \
	p5-Plack>0:www/p5-Plack

USES=	perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>

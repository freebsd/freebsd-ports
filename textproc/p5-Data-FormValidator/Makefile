# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Data-FormValidator
PORTVERSION=	4.81
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Validates user input (usually from an HTML form) based

BUILD_DEPENDS=	p5-CGI>=3.48:www/p5-CGI \
		p5-Date-Calc>=5.0:devel/p5-Date-Calc \
		p5-Email-Valid>=0:mail/p5-Email-Valid \
		p5-File-MMagic>=1.17:devel/p5-File-MMagic \
		p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-MIME-Types>=1.005:mail/p5-MIME-Types \
		p5-Perl6-Junction>=1.10:devel/p5-Perl6-Junction \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>

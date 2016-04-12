# $FreeBSD$

PORTNAME=	HTTP-Router
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of Yet Another Path Router for HTTP

BUILD_DEPENDS=	\
	p5-Class-Accessor>0:devel/p5-Class-Accessor \
	p5-Devel-Caller-Perl>0:devel/p5-Devel-Caller-Perl \
	p5-Filter>0:devel/p5-Filter \
	p5-Hash-AsObject>0:devel/p5-Hash-AsObject \
	p5-Lingua-EN-Inflect-Number>0:textproc/p5-Lingua-EN-Inflect-Number \
	p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
	p5-String-CamelCase>0:textproc/p5-String-CamelCase \
	p5-Text-SimpleTable>=0:textproc/p5-Text-SimpleTable \
	p5-Text-SimpleTemplate>0:textproc/p5-Text-SimpleTemplate \
	p5-URI-Template-Restrict>=0.05:net/p5-URI-Template-Restrict
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

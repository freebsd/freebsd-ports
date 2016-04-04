# Created by: ijliao
# $FreeBSD$

PORTNAME=	WebService-Technorati
PORTVERSION=	0.04
PORTREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Technorati web services interface

BUILD_DEPENDS=	p5-XML-XPath>=0:textproc/p5-XML-XPath \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	pod2html.pl
USE_PERL5=	configure

.include <bsd.port.mk>

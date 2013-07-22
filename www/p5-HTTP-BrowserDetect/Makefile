# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	HTTP-BrowserDetect
PORTVERSION=	1.54
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OALDERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Determine the Web browser, version, OS from an HTTP user agent string

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-FailWarnings>=0:${PORTSDIR}/devel/p5-Test-FailWarnings \
		p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

PERL_CONFIGURE=	yes

MAN3=		HTTP::BrowserDetect.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-JSON-PP>=0:${PORTSDIR}/converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>

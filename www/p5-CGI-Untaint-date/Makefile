# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Untaint-date
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Validate a date

BUILD_DEPENDS=	p5-CGI-Untaint>=0:www/p5-CGI-Untaint \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Date-Simple>=0:devel/p5-Date-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

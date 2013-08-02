# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	CGI-Cookie-XS
PORTVERSION=	0.18
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AGENT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTTP Cookie parser in C

BUILD_DEPENDS=	p5-Filter-Simple>=0:${PORTSDIR}/textproc/p5-Filter-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		CGI::Cookie::XS.3

.include <bsd.port.mk>

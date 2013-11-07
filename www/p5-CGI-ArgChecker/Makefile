# Created by: will
# $FreeBSD$

PORTNAME=	CGI-ArgChecker
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module implementing a cgi interface to String::Checker

BUILD_DEPENDS=	p5-String-Checker>=0:${PORTSDIR}/devel/p5-String-Checker
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

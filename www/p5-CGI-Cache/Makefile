# Created by: will
# $FreeBSD$

PORTNAME=	CGI-Cache
PORTVERSION=	1.42.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to cache output of time-intensive CGI scripts

BUILD_DEPENDS=	p5-Cache>=0:${PORTSDIR}/devel/p5-Cache \
		p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Tie-Restore>=0:${PORTSDIR}/devel/p5-Tie-Restore
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

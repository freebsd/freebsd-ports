# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-ExtDirect
PORTVERSION=	3.24
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl extension for creating Ext.Direct remoting in CGI applications

BUILD_DEPENDS=	p5-RPC-ExtDirect>=3.20:www/p5-RPC-ExtDirect \
		p5-CGI>4.20:www/p5-CGI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

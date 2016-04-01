# Created by: Oleg Mamontov <oleg@mamontov.net>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-AtomServer
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Atom API server for Catalyst applications

BUILD_DEPENDS=	p5-Catalyst-Runtime>=0:www/p5-Catalyst-Runtime	\
		p5-Catalyst-Plugin-Authentication>=0:www/p5-Catalyst-Plugin-Authentication	\
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1		\
		p5-XML-Atom>=0:textproc/p5-XML-Atom
RUN_DEPENDS=	p5-Catalyst-Runtime>=0:www/p5-Catalyst-Runtime	\
		p5-Catalyst-Plugin-Authentication>=0:www/p5-Catalyst-Plugin-Authentication	\
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1		\
		p5-XML-Atom>=0:textproc/p5-XML-Atom

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

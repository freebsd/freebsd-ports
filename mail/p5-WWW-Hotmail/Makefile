# Created by: Steven Kreuzer <skreuzer@f2o.org>
# $FreeBSD$

PORTNAME=	WWW-Hotmail
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	This module simplifies access to hotmail

BUILD_DEPENDS=	p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-Mail-Audit>=0:mail/p5-Mail-Audit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

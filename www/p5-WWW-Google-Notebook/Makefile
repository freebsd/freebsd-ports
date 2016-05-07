# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	WWW-Google-Notebook
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Perl interface for Google Notebook

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

DEPRECATED=		Google Notebook has shut down
EXPIRATION_DATE=	2016-06-30

.include <bsd.port.mk>

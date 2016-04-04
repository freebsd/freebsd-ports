# Created by: Daniel B. Hemmerich
# $FreeBSD$

PORTNAME=	CGI-Upload
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	CGI class for handling browser file uploads

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-BrowserDetect>=0:www/p5-HTTP-BrowserDetect \
		p5-File-MMagic>=0:devel/p5-File-MMagic \
		p5-CGI>=0:www/p5-CGI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

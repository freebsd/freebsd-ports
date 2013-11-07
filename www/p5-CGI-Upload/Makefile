# Created by: Daniel B. Hemmerich
# $FreeBSD$

PORTNAME=	CGI-Upload
PORTVERSION=	1.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CGI class for handling browser file uploads

BUILD_DEPENDS=	p5-HTTP-BrowserDetect>=0:${PORTSDIR}/www/p5-HTTP-BrowserDetect \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

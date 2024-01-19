PORTNAME=	CGI-Upload
PORTVERSION=	1.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	CGI class for handling browser file uploads
WWW=		https://metacpan.org/release/CGI-Upload

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-BrowserDetect>=0:www/p5-HTTP-BrowserDetect \
		p5-File-MMagic>=0:devel/p5-File-MMagic \
		p5-CGI>=0:www/p5-CGI

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	cgi.pl

.include <bsd.port.mk>

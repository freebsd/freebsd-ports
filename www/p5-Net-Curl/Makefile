PORTNAME=	Net-Curl
DISTVERSION=	0.57
PORTREVISION=	1
CATEGORIES=	www ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrew.fengler@scaleengine.com
COMMENT=	Perl interface for libcurl
WWW=		https://metacpan.org/dist/Net-Curl

LICENSE=	MIT

BUILD_DEPENDS=	p5-ExtUtils-PkgConfig>=1.16:devel/p5-ExtUtils-PkgConfig
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		localbase perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/Curl/Curl.so

.include <bsd.port.mk>

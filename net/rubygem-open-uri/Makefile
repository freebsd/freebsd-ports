PORTNAME=	open-uri
PORTVERSION=	0.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy-to-use wrapper for Net::HTTP, Net::HTTPS and Net::FTP

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-stringio>=0:devel/rubygem-stringio \
		rubygem-time>=0:devel/rubygem-time \
		rubygem-uri>=0:net/rubygem-uri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	metasploit-concern
PORTVERSION=	5.0.6
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatically include Modules from app/concerns
WWW=		https://github.com/rapid7/metasploit-concern

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel80>=8.0:databases/rubygem-activemodel80 \
		rubygem-activesupport80>=8.0:devel/rubygem-activesupport80 \
		rubygem-drb>=0:devel/rubygem-drb \
		rubygem-mutex_m>=0:devel/rubygem-mutex_m \
		rubygem-railties80>=8.0:www/rubygem-railties80 \
		rubygem-zeitwerk>=0:devel/rubygem-zeitwerk

NO_ARCH=	yes

USES=		gem

.include <bsd.port.mk>

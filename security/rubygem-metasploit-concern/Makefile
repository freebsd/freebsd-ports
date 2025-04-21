PORTNAME=	metasploit-concern
PORTVERSION=	5.0.4
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatically include Modules from app/concerns
WWW=		https://github.com/rapid7/metasploit-concern

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel71>=7.1:databases/rubygem-activemodel71 \
		rubygem-activesupport71>=7.1:devel/rubygem-activesupport71 \
		rubygem-railties71>=7.1:www/rubygem-railties71 \
		rubygem-zeitwerk>=0:devel/rubygem-zeitwerk

NO_ARCH=	yes

USES=		gem

.include <bsd.port.mk>

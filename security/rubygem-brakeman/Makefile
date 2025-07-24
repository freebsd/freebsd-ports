PORTNAME=	brakeman
PORTVERSION=	7.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Detect security vulnerabilities in Ruby on Rails applications via static analysis
WWW=		https://brakemanscanner.org/ \
		https://github.com/presidentbeef/brakeman

LICENSE=	BRAKEMAN
LICENSE_NAME=	Brakeman public use license
LICENSE_TEXT=	https://github.com/presidentbeef/brakeman/blob/main/LICENSE.md
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

RUN_DEPENDS=	rubygem-racc>=0:devel/rubygem-racc

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/brakeman

.include <bsd.port.mk>

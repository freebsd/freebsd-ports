PORTNAME=	bundler-audit
PORTVERSION=	0.9.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Patch-level verification for Bundled apps
WWW=		https://github.com/rubysec/bundler-audit

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-thor>=1.0<2:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/bundle-audit \
		bin/bundler-audit

.include <bsd.port.mk>

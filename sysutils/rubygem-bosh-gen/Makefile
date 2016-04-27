# $FreeBSD$

PORTNAME=	bosh-gen
PORTVERSION=	0.22.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generators for creating BOSH releases

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=4.0:devel/rubygem-activesupport4 \
		rubygem-bosh_cli>=0:sysutils/rubygem-bosh_cli \
		rubygem-bosh-template>=0:devel/rubygem-bosh-template \
		rubygem-cyoi>=0.10:devel/rubygem-cyoi \
		rubygem-fog>=1.11:devel/rubygem-fog \
		rubygem-fog-aws>=0.7.6:net/rubygem-fog-aws \
		rubygem-progressbar>=0:devel/rubygem-progressbar \
		rubygem-readwritesettings>=3.0:devel/rubygem-readwritesettings \
		rubygem-thor>=0:devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	lib/bosh/gen/generators/new_release_generator/templates/templates/make_manifest.tt \
		spec/fixtures/releases/s3test-boshrelease/templates/make_manifest

PLIST_FILES=	bin/bosh-gen

.include <bsd.port.mk>

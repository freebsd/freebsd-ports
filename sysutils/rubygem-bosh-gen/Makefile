# $FreeBSD$

PORTNAME=	bosh-gen
PORTVERSION=	0.97.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generators for creating BOSH releases

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=4.0:devel/rubygem-activesupport4 \
		rubygem-cyoi>=0.10:devel/rubygem-cyoi \
		rubygem-fog>=1.11:devel/rubygem-fog \
		rubygem-fog-aws>=0:net/rubygem-fog-aws \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-progressbar>=0:devel/rubygem-progressbar \
		rubygem-readwritesettings>=3.0:devel/rubygem-readwritesettings \
		rubygem-thor>=0:devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

PLIST_FILES=	bin/bosh-gen

SHEBANG_FILES=	lib/bosh/gen/generators/new_release_generator/templates/manifests/operators/pick-from-cloud-config.sh.tt

.include <bsd.port.mk>

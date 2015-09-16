# $FreeBSD$

PORTNAME=	bosh-gen
PORTVERSION=	0.19.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Generators for creating BOSH releases

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport4>=4.0:${PORTSDIR}/devel/rubygem-activesupport4 \
		rubygem-bosh_cli>=0:${PORTSDIR}/sysutils/rubygem-bosh_cli \
		rubygem-bosh-template>=0:${PORTSDIR}/devel/rubygem-bosh-template \
		rubygem-cyoi>=0.10:${PORTSDIR}/devel/rubygem-cyoi \
		rubygem-fog>=1.11:${PORTSDIR}/devel/rubygem-fog \
		rubygem-fog-aws>=0.1.1:${PORTSDIR}/net/rubygem-fog-aws \
		rubygem-progressbar>=0:${PORTSDIR}/devel/rubygem-progressbar \
		rubygem-readwritesettings>=3.0:${PORTSDIR}/devel/rubygem-readwritesettings \
		rubygem-thor>=0:${PORTSDIR}/devel/rubygem-thor

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/bosh-gen

.include <bsd.port.mk>

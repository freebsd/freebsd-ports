PORTNAME=	facter
PORTVERSION=	4.2.10
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Cross-platform Ruby library for retrieving facts from OS

LICENSE=	APACHE20

# rubygem-ffi is a soft dependency, but is used on FreeBSD to resolve some facts
RUN_DEPENDS=	rubygem-ffi>=1.0:devel/rubygem-ffi \
		rubygem-hocon>=1.3<2:devel/rubygem-hocon \
		rubygem-thor>=1.0.1<2.0:devel/rubygem-thor

USES=		cpe gem
CPE_VENDOR=	puppet
USE_RUBY=	yes

CONFLICTS_INSTALL=	facter # bin/facter

NO_ARCH=	yes

PLIST_FILES=	bin/facter ${GEMS_DIR}/facter

.include <bsd.port.pre.mk>

post-install:
	${RLN} ${STAGEDIR}/${PREFIX}/${GEMS_DIR}/facter-${PORTVERSION} ${STAGEDIR}/${PREFIX}/${GEMS_DIR}/facter

.include <bsd.port.post.mk>

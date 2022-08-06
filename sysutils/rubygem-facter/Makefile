PORTNAME=	facter
PORTVERSION=	4.2.11
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Cross-platform Ruby library for retrieving facts from OS

LICENSE=	APACHE20

PATCH_SITES=	https://patch-diff.githubusercontent.com/raw/puppetlabs/facter/pull/
PATCHFILES=	2497.diff 2510.diff
PATCH_DIST_STRIP=-p1

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
	(cd ${WRKSRC}/lib/facter/facts/freebsd && ${COPYTREE_SHARE} "ec2_metadata.rb ec2_userdata.rb ipaddress_interfaces.rb ipaddress6_interfaces.rb" ${STAGEDIR}/${PREFIX}/${GEMS_DIR}/facter-${PORTVERSION}/lib/facter/facts/freebsd)
	${RLN} ${STAGEDIR}/${PREFIX}/${GEMS_LIB_DIR} ${STAGEDIR}/${PREFIX}/${GEMS_DIR}/facter

.include <bsd.port.post.mk>

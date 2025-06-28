PORTNAME=	facter
PORTVERSION=	4.10.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Cross-platform Ruby library for retrieving facts from OS
WWW=		https://puppetlabs.com/facter

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-hocon>=1.3<2:devel/rubygem-hocon \
		rubygem-thor>=1.0.1<2.0:devel/rubygem-thor
# Soft dependencies that resolve more FreeBSD facts
RUN_DEPENDS+=	rubygem-ruby-augeas>0:textproc/rubygem-ruby-augeas \
		rubygem-ffi>=1.0:devel/rubygem-ffi \
		rubygem-rexml>0:textproc/rubygem-rexml \
		rubygem-sys-filesystem>0:sysutils/rubygem-sys-filesystem

USES=		cpe gem
CPE_VENDOR=	puppet

CONFLICTS_INSTALL=	facter rubygem-openfact # bin/facter

NO_ARCH=	yes

PLIST_FILES=	bin/facter ${GEMS_DIR}/facter

.include <bsd.port.pre.mk>

post-install:
	(cd ${WRKSRC}/lib/facter/facts/freebsd && ${COPYTREE_SHARE} "ec2_metadata.rb ec2_userdata.rb ipaddress_interfaces.rb ipaddress6_interfaces.rb" ${STAGEDIR}/${PREFIX}/${GEMS_DIR}/facter-${PORTVERSION}/lib/facter/facts/freebsd)
	${RLN} ${STAGEDIR}/${PREFIX}/${GEMS_LIB_DIR} ${STAGEDIR}/${PREFIX}/${GEMS_DIR}/facter

.include <bsd.port.post.mk>

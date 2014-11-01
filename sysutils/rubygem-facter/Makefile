# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	facter
PORTVERSION=	2.3.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG \
		http://downloads.puppetlabs.com/facter/

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Cross-platform Ruby library for retrieving facts from OS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/facter

OPTIONS_DEFINE=	ZFS_FACTS
ZFS_FACTS_DESC=	Generate ZFS-related facts

OPTIONS_DEFAULT=	ZFS_FACTS

.include <bsd.port.pre.mk>

# Restrict dmidecode dependency to Intel based systems
.if ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64"
RUN_DEPENDS+=	dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

post-patch:
.if empty(PORT_OPTIONS:MZFS_FACTS)
	@${REINPLACE_CMD} -e '/\-\ lib\/facter\/zfs_version.rb/d' ${WRKSRC}/${GEM_NAME}.gemspec
	@${REINPLACE_CMD} -e '/\-\ lib\/facter\/zpool_version.rb/d' ${WRKSRC}/${GEM_NAME}.gemspec
.endif

.include <bsd.port.post.mk>

# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	facter
PORTVERSION=	2.4.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG \
		http://downloads.puppetlabs.com/facter/

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Cross-platform Ruby library for retrieving facts from OS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/facter

OPTIONS_DEFINE=	ZFS_FACTS
ZFS_FACTS_DESC=	Generate ZFS-related facts

OPTIONS_DEFAULT=	ZFS_FACTS

.include <bsd.port.pre.mk>

# Restrict dmidecode dependency to Intel based systems
.if ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64"
RUN_DEPENDS+=	dmidecode:sysutils/dmidecode
.endif

post-patch-ZFS_FACTS-off:
	@${REINPLACE_CMD} -e 's/\,\ \"lib\/facter\/zfs_version.rb\"//' ${WRKSRC}/${PORTNAME}.gemspec
	@${REINPLACE_CMD} -e 's/\,\ \"lib\/facter\/zpool_version.rb\"//' ${WRKSRC}/${PORTNAME}.gemspec

.include <bsd.port.post.mk>

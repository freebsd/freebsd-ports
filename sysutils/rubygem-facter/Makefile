# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	facter
PORTVERSION=	2.5.1
PORTREVISION=	1
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

OPTIONS_DEFINE=	EC2_FACTS ZFS_FACTS
EC2_FACTS_DESC=	Generate AWS EC2 related facts
ZFS_FACTS_DESC=	Generate ZFS related facts

OPTIONS_DEFAULT=	EC2_FACTS ZFS_FACTS


.include <bsd.port.pre.mk>

# Restrict dmidecode dependency to x86-based systems
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
RUN_DEPENDS+=	dmidecode:sysutils/dmidecode
.endif

post-patch-EC2_FACTS-off:
	@${REINPLACE_CMD} -e 's/\,\ \"lib\/facter\/ec2.rb\"//' ${WRKSRC}/${PORTNAME}.gemspec
	@${REINPLACE_CMD} -e 's/\,\ \"lib\/facter\/ec2\/rest.rb\"//' ${WRKSRC}/${PORTNAME}.gemspec

post-patch-ZFS_FACTS-off:
	@${REINPLACE_CMD} -e 's/\,\ \"lib\/facter\/zfs_version.rb\"//' ${WRKSRC}/${PORTNAME}.gemspec
	@${REINPLACE_CMD} -e 's/\,\ \"lib\/facter\/zpool_version.rb\"//' ${WRKSRC}/${PORTNAME}.gemspec

.include <bsd.port.post.mk>

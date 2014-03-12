# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	facter
PORTVERSION=	1.7.5
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG \
		http://downloads.puppetlabs.com/facter/

MAINTAINER=	ports@robakdesign.com
COMMENT=	Cross-platform Ruby library for retrieving facts from OS

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/facter

.include <bsd.port.pre.mk>

# Restrict dmidecode dependency to i386 and amd64 systems
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
RUN_DEPENDS+=	dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

.include <bsd.port.post.mk>

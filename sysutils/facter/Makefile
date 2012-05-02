# New ports collection makefile for:	facter
# Date created:		2007-03-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	facter
PORTVERSION=	1.6.8
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://downloads.puppetlabs.com/facter/

MAINTAINER=	rouslan@rshell.net
COMMENT=	A cross-platform Ruby library for retrieving facts from OS

NO_BUILD=	yes

USE_RUBY=	yes

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && \
	${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb

# Restrict dmidecode dependency to i386 and amd64 systems
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
RUN_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

.include <bsd.port.post.mk>

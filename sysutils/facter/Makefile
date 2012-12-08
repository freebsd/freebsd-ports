# New ports collection makefile for:	facter
# Date created:		2007-03-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	facter
PORTVERSION=	1.6.16
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://downloads.puppetlabs.com/facter/

MAINTAINER=	rouslan@rshell.net
COMMENT=	A cross-platform Ruby library for retrieving facts from OS

NO_BUILD=	yes

USE_RUBY=	yes

MAN8=		facter.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

# Restrict dmidecode dependency to i386 and amd64 systems
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
RUN_DEPENDS=    dmidecode:${PORTSDIR}/sysutils/dmidecode
.endif

do-install:
	cd ${WRKSRC} && \
	${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb

.include <bsd.port.post.mk>

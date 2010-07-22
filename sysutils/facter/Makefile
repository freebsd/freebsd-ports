# New ports collection makefile for:	facter
# Date created:		2007-03-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	facter
PORTVERSION=	1.5.7
PORTREVISION=	1
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://www.reductivelabs.com/downloads/facter/

MAINTAINER=	rouslan@rshell.net
COMMENT=	A cross-platform Ruby library for retrieving facts from OS

RUN_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode

NO_BUILD=	yes

USE_RUBY=	yes

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && \
	${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb

.include <bsd.port.post.mk>

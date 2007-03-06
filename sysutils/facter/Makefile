# New ports collection makefile for:	rubygem-facter
# Date created:		2007-03-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.mine.nu>
#
# $FreeBSD$
#

PORTNAME=	facter
PORTVERSION=	1.3.6
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://www.reductivelabs.com/downloads/facter/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cherry@trombik.mine.nu
COMMENT=	A cross-platform Ruby library for retrieving facts from OS

NO_BUILD=	yes

USE_RUBY=	yes

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && \
	${SETENV} DSTDIR=${DSTDIR}/${PREFIX} ${RUBY} ${WRKSRC}/install.rb

.include <bsd.port.post.mk>

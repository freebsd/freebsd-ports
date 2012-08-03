# New ports collection makefile for:	rubygem-termtter
# Date created:		2009-07-12
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	termtter
PORTVERSION=	1.11.0
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Terminal based Twitter client

RUN_DEPENDS=	rubygem-json>=1.1.3:${PORTSDIR}/devel/rubygem-json \
		rubygem-termcolor>=1.0.0:${PORTSDIR}/textproc/rubygem-termcolor \
		rubygem-rubytter>=1.4.0:${PORTSDIR}/net/rubygem-rubytter \
		rubygem-highline>=1.5.0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-notify>=0.2.1:${PORTSDIR}/devel/rubygem-notify

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/termtter

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif
.include <bsd.port.post.mk>

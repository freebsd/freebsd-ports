# Ports collection makefile for:	rubygem-feedzirra
# Date created:				08 June 2010
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	feedzirra
PORTVERSION=	0.0.23
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	A feed fetching and parsing library

RUN_DEPENDS=	rubygem-activesupport>=2.0.0:${PORTSDIR}/devel/rubygem-activesupport \
	rubygem-builder>=2.1.2:${PORTSDIR}/devel/rubygem-builder \
	rubygem-nokogiri>=0.0.0:${PORTSDIR}/textproc/rubygem-nokogiri \
	rubygem-loofah>=0.3.1:${PORTSDIR}/textproc/rubygem-loofah \
	rubygem-curb>=0.2.3:${PORTSDIR}/ftp/rubygem-curb \
	rubygem-sax-machine>=0.0.12:${PORTSDIR}/textproc/rubygem-sax-machine

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

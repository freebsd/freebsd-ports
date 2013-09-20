# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws-s3
PORTVERSION=	0.6.3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Client library for Amazon S3 REST API

RUN_DEPENDS=	rubygem-xml-simple>=0:${PORTSDIR}/textproc/rubygem-xml-simple \
		rubygem-builder>=0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-mime-types>=0:${PORTSDIR}/misc/rubygem-mime-types

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/s3sh

NO_STAGE=	yes
.include <bsd.port.mk>

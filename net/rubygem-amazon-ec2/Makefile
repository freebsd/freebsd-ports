# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amazon-ec2
PORTVERSION=	0.9.17
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Library for accessing the Amazon Web Services APIs

RUN_DEPENDS=	rubygem-xml-simple>=1.0.12:${PORTSDIR}/textproc/rubygem-xml-simple

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/awshell bin/ec2-gem-example.rb bin/ec2-gem-profile.rb bin/ec2sh bin/setup.rb

.include <bsd.port.mk>

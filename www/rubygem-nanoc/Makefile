# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nanoc
PORTVERSION=	3.6.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Simple but flexible static site generator

RUN_DEPENDS=	rubygem-cri>=2.2:${PORTSDIR}/devel/rubygem-cri

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/nanoc

NO_STAGE=	yes
.include <bsd.port.mk>

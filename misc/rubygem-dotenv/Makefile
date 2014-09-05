# $FreeBSD$

PORTNAME=	dotenv
PORTVERSION=	0.11.1
CATEGORIES=	misc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Loads environment variables from `.env`

RUN_DEPENDS=	rubygem-dotenv-deployment>=0.0.2:${PORTSDIR}/devel/rubygem-dotenv-deployment

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES+=	bin/dotenv

.include <bsd.port.mk>

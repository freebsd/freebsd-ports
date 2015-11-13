# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	5.0.4
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties4>=4.0.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-sass>=3.1:${PORTSDIR}/textproc/rubygem-sass \
		rubygem-sprockets3>=3.0.3:${PORTSDIR}/devel/rubygem-sprockets3 \
		rubygem-sprockets-rails>=2.0:${PORTSDIR}/devel/rubygem-sprockets-rails \
		rubygem-tilt>=1.1:${PORTSDIR}/devel/rubygem-tilt

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

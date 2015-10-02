# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opennebula
PORTVERSION=	4.14.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Libraries needed to talk to OpenNebula

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-json>=0:${PORTSDIR}/devel/rubygem-json \
		rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-rbvmomi>=0:${PORTSDIR}/net/rubygem-rbvmomi

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

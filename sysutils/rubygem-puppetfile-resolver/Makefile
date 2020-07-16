# $FreeBSD$

PORTNAME=	puppetfile-resolver
DISTVERSION=	0.3.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Dependency resolver for Puppetfiles as a gem

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-molinillo>=0.6:devel/rubygem-molinillo \
		rubygem-semantic_puppet>=1.0:devel/rubygem-semantic_puppet

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>

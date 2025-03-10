PORTNAME=	gitlab-cloud-connector
PORTVERSION=	1.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	CloudConnector and lib for GitLab projects
WWW=		https://gitlab.com/gitlab-org/cloud-connector/gitlab-cloud-connector

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=7.0<8:devel/rubygem-activesupport70 \
		rubygem-jwt29>=2.9.3<2.10:www/rubygem-jwt29

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

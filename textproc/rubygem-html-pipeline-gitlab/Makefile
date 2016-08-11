# $FreeBSD$

PORTNAME=	html-pipeline-gitlab
PORTVERSION=	0.2.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Extension filters for html-pipeline used by GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=4:www/rubygem-actionpack4 \
		rubygem-gitlab_emoji>=0.1:graphics/rubygem-gitlab_emoji \
		rubygem-html-pipeline>=1.11.0:textproc/rubygem-html-pipeline \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-sanitize>=2.1:textproc/rubygem-sanitize

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

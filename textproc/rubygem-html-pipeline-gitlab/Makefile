# $FreeBSD$

PORTNAME=	html-pipeline-gitlab
PORTVERSION=	0.2.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Extension filters for html-pipeline used by GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=4:${PORTSDIR}/www/rubygem-actionpack4 \
		rubygem-gitlab_emoji>=0.1.0:${PORTSDIR}/graphics/rubygem-gitlab_emoji \
		rubygem-html-pipeline>=1.11.0:${PORTSDIR}/textproc/rubygem-html-pipeline \
		rubygem-mime-types>0:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-sanitize>=2.1:${PORTSDIR}/textproc/rubygem-sanitize

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

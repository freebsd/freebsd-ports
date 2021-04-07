PORTNAME=	gollum-grit_adapter
PORTVERSION=	1.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	10

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Adapter for Gollum to use Grit at the backend

LICENSE=	MIT

RUN_DEPENDS=	rubygem-gitlab-grit>=2.7.1:textproc/rubygem-gitlab-grit

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.0\.

.include <bsd.port.mk>

PORTNAME=	gitlab-gollum-rugged_adapter
PORTVERSION=	0.4.4.4.gitlab.1
PORTREVISION=	0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Adapter for Gollum to use Rugged (libgit2) at the backend
WWW=		https://gitlab.com/gitlab-org/gitlab-gollum-rugged_adapter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mime-types>=1.15:misc/rubygem-mime-types \
		rubygem-rugged>=1.0<2:devel/rubygem-rugged

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

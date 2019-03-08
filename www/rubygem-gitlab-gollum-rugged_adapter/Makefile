# $FreeBSD$

PORTNAME=	gitlab-gollum-rugged_adapter
PORTVERSION=	0.4.4.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Adapter for Gollum to use Rugged (libgit2) at the backend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mime-types>=1.15:misc/rubygem-mime-types \
		rubygem-rugged>=0.25:devel/rubygem-rugged

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

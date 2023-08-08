PORTNAME=	gollum-rugged_adapter
PORTVERSION=	2.1.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Adapter for Gollum to use Rugged (libgit2) at the backend
WWW=		https://github.com/gollum/rugged_adapter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mime-types>=3.4<4:misc/rubygem-mime-types \
		rubygem-rugged>=1.5<2:devel/rubygem-rugged

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

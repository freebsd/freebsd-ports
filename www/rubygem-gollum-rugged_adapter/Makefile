# Created by: Torsten Zuehlsdorff <ports@toco-domains.de>

PORTNAME=	gollum-rugged_adapter
PORTVERSION=	1.1.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Adapter for Gollum to use Rugged (libgit2) at the backend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mime-types>=3.3.1:misc/rubygem-mime-types \
		rubygem-rugged>=1.0:devel/rubygem-rugged

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

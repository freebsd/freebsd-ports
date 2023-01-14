PORTNAME=	rabbirack
PORTVERSION=	2.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tool to control Rabbit from web browser
WWW=		https://rabbit-shocker.org/en/rabbirack/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

RUN_DEPENDS=	rubygem-haml>0:www/rubygem-haml \
		rubygem-locale>=2.0.6:devel/rubygem-locale \
		rubygem-rabbit>=2.0.0:misc/rubygem-rabbit \
		rubygem-sinatra>0:www/rubygem-sinatra

NO_ARCH=	yes
USES=		gem gettext
PLIST_FILES=	bin/rabbirack

.include <bsd.port.mk>

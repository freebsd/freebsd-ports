# $FreeBSD$

PORTNAME=	bootstrap-sass
PORTVERSION=	3.3.5.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Bootstrap by Twitter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-autoprefixer-rails>=5.0.0.1:${PORTSDIR}/textproc/rubygem-autoprefixer-rails \
		rubygem-sass>=3.3.0:${PORTSDIR}/textproc/rubygem-sass

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

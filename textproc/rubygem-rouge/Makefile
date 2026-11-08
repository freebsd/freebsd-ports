PORTNAME=	rouge
PORTVERSION=	5.1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, easy-to-extend drop-in replacement for pygments
WWW=		https://github.com/jneen/rouge

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-strscan>=3.1<4:devel/rubygem-strscan

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rougify

.include <bsd.port.mk>

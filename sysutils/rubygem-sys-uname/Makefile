PORTNAME=	sys-uname
PORTVERSION=	1.4.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface for getting system information
WWW=		https://github.com/djberg96/sys-uname

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi>=1.1<2:devel/rubygem-ffi \
		rubygem-memoist>=0.16.2<0.17:devel/rubygem-memoist

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

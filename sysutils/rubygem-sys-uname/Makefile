PORTNAME=	sys-uname
PORTVERSION=	1.4.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface for getting system information
WWW=		https://github.com/djberg96/sys-uname

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi>=1.1<2:devel/rubygem-ffi \
		rubygem-memoist3>=1.0.0<1.1:devel/rubygem-memoist3

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

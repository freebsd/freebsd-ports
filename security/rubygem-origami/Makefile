# $FreeBSD$

PORTNAME=	origami
PORTVERSION=	2.0.4
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby framework to parse analyze and forge PDF documents

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	rubygem-colorize>=0.7:devel/rubygem-colorize

NO_ARCH=	yes

USES=		gem shebangfix
SHEBANG_FILES=	examples/*/*.rb
USE_RUBY=	yes

.include <bsd.port.mk>

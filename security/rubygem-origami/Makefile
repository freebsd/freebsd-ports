PORTNAME=	origami
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby framework to parse analyze and forge PDF documents
WWW=		https://github.com/gdelugre/origami

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	rubygem-colorize>=0.7:devel/rubygem-colorize \
		rubygem-matrix>=0:math/rubygem-matrix \
		rubygem-rexml>=0:textproc/rubygem-rexml

NO_ARCH=	yes

USES=		gem shebangfix
SHEBANG_FILES=	examples/*/*.rb

.include <bsd.port.mk>

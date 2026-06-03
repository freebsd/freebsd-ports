PORTNAME=	nanomsg
PORTVERSION=	1.1.5
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	crest@bultmann.eu
COMMENT=	Socket library that provides several common communication patterns
WWW=		https://nanomsg.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pathfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_CMAKE_BOOL=	NN_ENABLE_DOC

.include <bsd.port.mk>

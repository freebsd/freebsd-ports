PORTNAME=	psych
PORTVERSION=	5.3.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	YAML parser and emitter
WWW=		https://github.com/ruby/psych

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyaml.so:textproc/libyaml
RUN_DEPENDS=	rubygem-date>=0:devel/rubygem-date \
		rubygem-stringio>=0:devel/rubygem-stringio

USES=		gem

.include <bsd.port.mk>

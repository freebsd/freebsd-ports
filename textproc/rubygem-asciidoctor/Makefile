PORTNAME=	asciidoctor
PORTVERSION=	2.0.26
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, open source text processor and publishing toolchain
WWW=		https://asciidoctor.org/ \
		https://github.com/asciidoctor/asciidoctor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/asciidoctor

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 4.0
RUN_DEPENDS+=	rubygem-logger>=0:devel/rubygem-logger
.endif

.include <bsd.port.post.mk>

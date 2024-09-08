PORTNAME=	dartsass # please update textproc/quarto when the path to the sass executable changes
PORTVERSION=	1.49.8
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	RubyGem wrapper for the Dart Sass binary
WWW=		https://github.com/ayushn21/dartsass-ruby

LICENSE=	MIT

USES=		gem

PLIST_FILES=	bin/dartsass

# The port installs binaries world writeable
# Reported upstream here: https://github.com/ayushn21/dartsass-ruby/issues/1
# Fix this here, till they provide an upstream fix for this security problem
post-extract:
	${CHMOD} 0755 ${WRKSRC}/exe/linux/sass
	${CHMOD} 0755 ${WRKSRC}/exe/darwin/sass
	${CHMOD} 0755 ${WRKSRC}/exe/darwin/src/dart

.include <bsd.port.mk>

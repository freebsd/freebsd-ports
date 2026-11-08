PORTNAME=		kiss-templates
PORTVERSION=		0.19
PORTREVISION=		14
CATEGORIES=		textproc

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Type safe "Keep it simple, stupid" text templates for C++
WWW=		https://github.com/rbock/kiss-templates

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

DEPRECATED=		Abandoned upstream, has no uses in tree, does not build with CMake 4
EXPIRATION_DATE=	2026-11-30

USES=			cmake compiler:c++11-lang
USE_GITHUB=		yes
GH_ACCOUNT=		rbock

PLIST_FILES=		bin/kiste2cpp \
			include/kiste/cpp.h \
			include/kiste/html.h \
			include/kiste/kiste.h \
			include/kiste/raw.h \
			include/kiste/raw_type.h \
			include/kiste/serializer_builder.h \
			include/kiste/terminal.h

.include <bsd.port.mk>

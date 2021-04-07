PORTNAME=		kiss-templates
PORTVERSION=		0.19
PORTREVISION=		13
CATEGORIES=		textproc

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Type safe "Keep it simple, stupid" text templates for C++

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

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

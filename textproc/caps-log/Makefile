PORTNAME=	caps-log
DISTVERSION=	1.2.1-22
DISTVERSIONSUFFIX=	-gd8580a2
CATEGORIES=	textproc

MAINTAINER=	varinka@FreeBSD.am
COMMENT=	Small TUI journaling tool
WWW=		https://github.com/NikolaDucak/caps-log/

LICENSE=	MIT

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libftxui-screen.so:devel/ftxui \
		libgit2.so:devel/libgit2

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	NikolaDucak
GH_PROJECT=	caps-log

LDFLAGS+=	-lpthread

PLIST_FILES=	bin/caps-log

.include <bsd.port.mk>

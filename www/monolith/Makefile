PORTNAME=	monolith
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.3
PORTREVISION=	5
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	CLI tool for saving complete web pages as a single HTML file
WWW=		https://github.com/Y2Z/monolith

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake

USES=		cargo perl5 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Y2Z
USE_PERL5=	build

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

.include <bsd.port.mk>

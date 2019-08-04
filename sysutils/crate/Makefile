# $FreeBSD$

PORTNAME=	crate
DISTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Containerizer for FreeBSD (alpha-software, expect bugs)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11=		STL feature 'filesystem' isn't available on 11
.if defined(PACKAGE_BUILDING)
BROKEN_FreeBSD_12=		STL feature 'filesystem' isn't available in 12.0-RELEASE-p7
.endif

BUILD_DEPENDS=	rang>0:devel/rang
LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp

USES=		compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	yurivict

PLIST_FILES=	bin/${PORTNAME} \
		man/man5/${PORTNAME}.5.gz

OPTIONS_DEFINE=			EXAMPLES

EXAMPLES_INSTALL_TARGET=	install install-examples
PORTEXAMPLES=			*

.include <bsd.port.mk>

PORTNAME=	flvmeta
DISTVERSION=	1.2.2.20210819
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	earl@eeg3.net
COMMENT=	Manipulation tool for Adobe Flash Video files (FLV)
WWW=		https://github.com/noirotm/flvmeta

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	noirotm
GH_TAGNAME=	62e30a7

PLIST_FILES=	bin/flvmeta \
		share/man/man1/flvmeta.1.gz

CMAKE_ON=	FLVMETA_USE_SYSTEM_LIBYAML

post-patch:
	@${RM} -r ${WRKSRC}/src/libyaml
	@${REINPLACE_CMD} -e 's|add_subdirectory(man)||g' \
	    ${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/flvmeta.1 \
	    ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

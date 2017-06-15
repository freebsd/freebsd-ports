# $FreeBSD$

PORTNAME=	amtc
PORTVERSION=	0.8.5
CATEGORIES=	sysutils

MAINTAINER=	tony.li@tony.li
COMMENT=	Threaded Intel AMT/vPro mass management tool

LICENSE=	CC-BY-3.0

BUILD_DEPENDS=	xxd:editors/vim-lite
LIB_DEPENDS+=	libgcrypt.so:security/libgcrypt \
		libcurl.so:ftp/curl

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	schnoddelbotz
GH_TAGNAME=	e7822e8
USE_PERL5=	build
SHEBANG_FILES=	${WRKSRC}/../amtc-web/cli/amtc-web.phpsh

WRKSRC_SUBDIR=	src

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/amtc

.include <bsd.port.mk>

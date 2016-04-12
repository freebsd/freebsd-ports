# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	jq
PORTVERSION=	1.5
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	textproc

MAINTAINER=	yuri@rawbw.com
COMMENT=	Lightweight and flexible command-line JSON processor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	stedolan

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" \
		--disable-maintainer-mode
USE_CSTD=	gnu99
USE_LDCONFIG=	yes
USES=		gmake libtool
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS ONIGURUMA
OPTIONS_DEFAULT=ONIGURUMA

DOCS_MAKE_ARGS_OFF=	docdir=
DOCS_CONFIGURE_ENABLE=	docs

ONIGURUMA_DESC=		With oniguruma BSDL regular expression library
ONIGURUMA_LIB_DEPENDS=	libonig.so:devel/oniguruma5
#ONIGURUMA_CONFIGURE_WITH=oniguruma=${LOCALBASE} # pending resolution of https://github.com/stedolan/jq/issues/1021, next line is the workaround
ONIGURUMA_CONFIGURE_ON=	--with-oniguruma=${LOCALBASE}

.include <bsd.port.mk>

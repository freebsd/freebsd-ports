# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	jq
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.6
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and flexible command-line JSON processor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_GITHUB=	yes
GH_ACCOUNT=	stedolan
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" \
		--disable-maintainer-mode
USE_CSTD=	gnu99
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=			DOCS ONIGURUMA
OPTIONS_DEFAULT=		ONIGURUMA

DOCS_MAKE_ARGS_OFF=		docdir=
DOCS_CONFIGURE_ENABLE=		docs

ONIGURUMA_DESC=			With oniguruma BSDL regular expression library
ONIGURUMA_LIB_DEPENDS=		libonig.so:devel/oniguruma
ONIGURUMA_CONFIGURE_WITH=	oniguruma=${LOCALBASE}

.include <bsd.port.mk>

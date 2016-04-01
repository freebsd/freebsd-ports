# $FreeBSD$

PORTNAME=	mono-zeroconf
PORTVERSION=	0.9.0
CATEGORIES=	net
MASTER_SITES=	http://download.banshee.fm/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Cross platform Zero Configuration Networking library for Mono

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/avahi-sharp.pc:net/avahi-sharp
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
USES=		gmake mono pathfix pkgconfig shebangfix
bash_CMD=	${SH}
SHEBANG_FILES=	src/MZClient/mzclient.in
CONFIGURE_ARGS+=	--program-transform-name="" \
			--disable-mdnsresponder
MAKE_JOBS_UNSAFE=	yes
DOCS_CONFIGURE_ENABLE=	docs

.include <bsd.port.mk>

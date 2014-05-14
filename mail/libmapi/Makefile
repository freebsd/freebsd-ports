# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmapi
PORTVERSION=	2.1
CATEGORIES=	mail
MASTER_SITES=	http://tracker.openchange.org/attachments/download/${DOWNLOADCODE}/
DISTNAME=	openchange-${PORTVERSION}-${CODENAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Open Source implementation of Microsoft Exchange protocols

BUILD_DEPENDS=	samba4>=4.0.1:${PORTSDIR}/net/samba4 \
		p5-Parse-Pidl>=4.0.1:${PORTSDIR}/devel/p5-Parse-Pidl
LIB_DEPENDS=	libical.so:${PORTSDIR}/devel/libical \
		libtdb.so:${PORTSDIR}/databases/tdb \
		libtevent.so:${PORTSDIR}/devel/tevent \
		libtalloc.so:${PORTSDIR}/devel/talloc
RUN_DEPENDS=	samba4>=4.0.1:${PORTSDIR}/net/samba4

CODENAME=	QUADRANT
DOWNLOADCODE=	244

USE_SQLITE=	3
USES=		gmake pathfix pkgconfig shebangfix
USE_PYTHON=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-samba=${LOCALBASE}
CONFIGURE_ENV=	ac_cv_path_DOXYGEN="" \
		PYTHON_CONFIG=${LOCALBASE}/bin/python${PYTHON_VER}-config
SHEBANG_FILES=	libmapi/conf/mparse.pl \
		script/check_exchange \
		setup/openchange_newuser \
		setup/openchange_provision

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BOOST DOXYGEN
OPTIONS_DEFAULT=BOOST
BOOST_LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
BOOST_CONFIGURE_ENV_OFF=	ov_cv_boost_thread=no
BOOST_DESC=	libmapi C++ library (needs boost)
DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_path_DOXYGEN=""

CONFIGURE_ARGS+=	--disable-pymapi
#  --enable-openchange-qt4 Compile OpenChange Qt4 wrapper.

post-patch:
	@${REINPLACE_CMD} -e "s/mkdir --parent/mkdir -p/g; \
		s,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,g" \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openchange
	cd ${WRKSRC}/doc/doxygen/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/openchange/
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/lib*.so.*
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/shared-modules/dcerpc_server/dcesrv_mapiproxy.so
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/modules/dcerpc_mapiproxy*/*.so

.include <bsd.port.mk>

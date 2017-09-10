# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmapi
PORTVERSION=	2.3
DISTVERSIONPREFIX=	openchange-
DISTVERSIONSUFFIX=	-VULCAN
PORTREVISION=	9
CATEGORIES=	mail

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Open Source implementation of Microsoft Exchange protocols

BUILD_DEPENDS=	${SAMBA_DEP} \
		${LOCALBASE}/bin/flex:textproc/flex \
		p5-Parse-Pidl>=4.0.1:devel/p5-Parse-Pidl
LIB_DEPENDS=	libical.so:devel/libical \
		libnanomsg.so:net/nanomsg \
		libmemcached.so:databases/libmemcached \
		libcheck.so:devel/check \
		libtdb.so:databases/tdb \
		libtevent.so:devel/tevent \
		libtalloc.so:devel/talloc
RUN_DEPENDS=	${SAMBA_DEP}

USE_MYSQL=	yes
USES=		autoreconf:build bison compiler:c++11-lib gmake pathfix \
		pkgconfig python samba:lib shebangfix sqlite
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	openchange
GH_PROJECT=	openchange
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-samba=${LOCALBASE}
CONFIGURE_ENV=	PYTHON_CONFIG=${LOCALBASE}/bin/python${PYTHON_VER}-config \
		FLEX=${LOCALBASE}/bin/flex
SHEBANG_FILES=	libmapi/conf/mparse.pl \
		script/check_exchange \
		script/mkproto.pl \
		setup/openchange_group \
		setup/openchange_migrate \
		setup/openchange_neworganization \
		setup/openchange_newuser \
		setup/openchange_provision

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BOOST DOXYGEN
OPTIONS_DEFAULT=BOOST
BOOST_LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
BOOST_CONFIGURE_ENV_OFF=	ov_cv_boost_thread=no
BOOST_DESC=	libmapi C++ library (needs boost)
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_path_DOXYGEN=""
PLIST_SUB=	SAMBA=${SAMBAPORT:T}

.include <bsd.port.pre.mk>

.if ${SAMBA_DEFAULT} == 4.4
BROKEN=		fails to build
.endif

#  --enable-openchange-qt4 Compile OpenChange Qt4 wrapper.

post-patch:
	@${REINPLACE_CMD} -e "s/mkdir --parent/mkdir -p/g" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<endian.h>|<sys/endian.h>|g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|libnanomsg|nanomsg|g' \
		${WRKSRC}/configure.ac

pre-configure:
	@cd ${WRKSRC} && sh autogen.sh

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/openchange
	cd ${WRKSRC}/doc/doxygen/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/openchange/
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/lib*.so.*
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/shared-modules/dcerpc_server/*.so
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/modules/dcerpc_mapiproxy*/*.so

.include <bsd.port.post.mk>

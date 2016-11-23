# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmapi
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	https://github.com/openchange/openchange/archive/
DISTNAME=	openchange-${PORTVERSION}-${CODENAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Open Source implementation of Microsoft Exchange protocols

BUILD_DEPENDS=	${SAMBA_DEP} \
		${LOCALBASE}/bin/flex:textproc/flex \
		p5-Parse-Pidl>=4.0.1:devel/p5-Parse-Pidl
LIB_DEPENDS=	libical.so:devel/libical \
		libnanomsg.so:net/nanomsg \
		libmemcached.so:databases/libmemcached \
		libcheck.so:devel/libcheck \
		libtdb.so:databases/tdb \
		libtevent.so:devel/tevent \
		libtalloc.so:devel/talloc
RUN_DEPENDS=	${SAMBA_DEP}

CODENAME=	VULCAN
WRKSRC=		${WRKDIR}/openchange-openchange-${PORTVERSION}-${CODENAME}

USE_MYSQL=	yes
USES=		autoreconf:build bison compiler:c++11-lib gmake pathfix \
		pkgconfig python shebangfix sqlite
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
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
# SAMBA43
OPTIONS_DEFAULT=BOOST
BOOST_LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
BOOST_CONFIGURE_ENV_OFF=	ov_cv_boost_thread=no
BOOST_DESC=	libmapi C++ library (needs boost)
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_path_DOXYGEN=""
SAMBA43_DESC=	Build agains samba 4.3 instead of 4.2

.include <bsd.port.options.mk>

# no support for samba 4.3 yet
.if ${PORT_OPTIONS:MSAMBA43}
SAMBA_DEP=	samba43>=4.3.0:net/samba43
PLIST_SUB+=	SAMBA=samba43
.else
SAMBA_DEP=	samba42>=4.2.0:net/samba42
PLIST_SUB+=	SAMBA=samba42
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

.include <bsd.port.mk>

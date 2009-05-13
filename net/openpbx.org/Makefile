# New ports collection makefile for:	openpbx
# Date created:				3 April 2007
# Whom:					Maxim Sobolev <sobomax@sippysoft.com>
#
# $FreeBSD$
#

PORTNAME=	openpbx.org
PORTVERSION=	1.2
DISTVERSION=	1.2_rc3
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.openpbx.org/releases/

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

LIB_DEPENDS=	spandsp.2:${PORTSDIR}/comms/spandsp-devel

BROKEN=		Unfetchable

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tiff-includes=${LOCALBASE}/include \
		--with-tiff-libs=${LOCALBASE}/lib \
		--with-directory-layout=lsb \
		--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_GMAKE=	yes
USE_RC_SUBR=	openpbx
MAN8=		openpbx.8
OPTIONS=	SPEEX		"Enable speex codec" on \
		OGGVORBIS	"Enable Ogg Vorbis support" on \
		ODBC		"Enable ODBC support" off \
		MYSQL		"Enable MySQL support" off \
		POSTGRES	"Enable PostgreSQL support" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPTIONS+=	ZAPTEL		"Enable Zaptel hardware support" on
.else
WITHOUT_ZAPTEL=	yes
.endif

.if defined(WITHOUT_ZAPTEL)
PLIST_SUB+=	WITH_ZAPTEL="@comment "
CONFIGURE_ARGS+= --disable-zaptel
.else
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
RUN_DEPENDS+	${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
PLIST_SUB+=	WITH_ZAPTEL=""
CONFIGURE_ARGS+= --enable-zaptel
.endif

.if defined(WITHOUT_ODBC)
PLIST_SUB+=	WITH_ODBC="@comment "
CONFIGURE_ARGS+= --disable-odbc
.else
PLIST_SUB+=	WITH_ODBC=""
CONFIGURE_ARGS+= --enable-odbc \
		 --with-cdr_odbc \
		 --with-res_config_odbc \
		 --with-res_odbc
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
.endif

.if defined(WITHOUT_POSTGRES)
PLIST_SUB+=	WITH_POSTGRES="@comment "
CONFIGURE_ARGS+= --disable-postgresql
.else
PLIST_SUB+=	WITH_POSTGRES=""
USE_PGSQL=	yes
CONFIGURE_ARGS+= --enable-postgresql \
		 --with-app_sql_postgres \
		 --with-cdr_pgsql \
		 --with-res_config_pgsql
.endif

.if defined(WITHOUT_MYSQL)
PLIST_SUB+=	WITH_MYSQL="@comment "
CONFIGURE_ARGS+= --disable-mysql
.else
PLIST_SUB+=	WITH_MYSQL=""
USE_MYSQL=	yes
CONFIGURE_ARGS+= --enable-mysql \
		 --with-app_sql_mysql \
		 --with-cdr_mysql \
		 --with-res_config_mysql
.endif

.if defined(WITHOUT_SPEEX)
PLIST_SUB+=	WITH_SPEEX="@comment "
CONFIGURE_ARGS+= --without-codec_speex
.else
PLIST_SUB+=	WITH_SPEEX=""
CONFIGURE_ARGS+= --with-codec_speex
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.endif

.if defined(WITHOUT_OGGVORBIS)
PLIST_SUB+=	WITH_OGGVORBIS="@comment "
CONFIGURE_ARGS+= --without-format_oggvorbis
.else
PLIST_SUB+=	WITH_OGGVORBIS=""
CONFIGURE_ARGS+= --with-format_oggvorbis
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

pre-su-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

.include <bsd.port.post.mk>

# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sparforte
PORTVERSION=	2.0.2
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	shells lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shell and scripting language for mission-critical, scalable projects

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	kburtch
GH_PROJECT=	SparForte

USES=		ada bdb:48 gettext-runtime gmake pkgconfig readline:port
USE_SDL=	sdl image
HAS_CONFIGURE=	yes
MAKE_ARGS+=	RPM_BUILD_ROOT=1
PORTDOCS=	*

BROKEN_aarch64=		fails to compile: gnat1: error: unknown value aarch64 for -march

# Repurpose CXXFLAGS for gnatprep options
CXXFLAGS:=	-DREADLINE=true \
		-DBDB=true

PREPFILES=	world.ads \
		user_io-getline.adb \
		scanner_res.ads \
		scanner_res.adb \
		parser.adb \
		builtins.adb \
		parser_db.adb \
		parser_dbm.adb \
		parser_mysql.adb \
		parser_mysqlm.adb \
		parser_sound.adb \
		parser_pen.adb \
		parser_gnat_cgi.adb \
		parser_bdb.adb \
		parser_btree_io.adb \
		parser_hash_io.adb

CONFIGURE_SCRIPT=	new_configure
MAKE_JOBS_UNSAFE=	yes # adacgi seems to be unsafe

OPTIONS_DEFINE=		CGI OPENGL SOUND DOCS EXAMPLES
OPTIONS_GROUP=		Database
OPTIONS_GROUP_Database=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL PGSQL OPENGL SOUND

MYSQL_USES=		mysql
MYSQL_CXXFLAGS=		-DMYSQL=true
MYSQL_CXXFLAGS_OFF=	-DMYSQL=false

PGSQL_USES=		pgsql ssl
PGSQL_CXXFLAGS=		-DPOSTGRES=true
PGSQL_CXXFLAGS_OFF=	-DPOSTGRES=false

OPENGL_USE=		GL=gl,glu
OPENGL_CXXFLAGS=	-DOPENGL=true
OPENGL_CXXFLAGS_OFF=	-DOPENGL=false

SOUND_LIB_DEPENDS=	libgstreamer-0.10.so:multimedia/gstreamer
SOUND_USE=		GNOME=glib20,libxml2
SOUND_CXXFLAGS=		-DSOUND=true
SOUND_CXXFLAGS_OFF=	-DSOUND=false

CGI_DESC=		Common Gateway Interface (breaks other features)
CGI_CXXFLAGS=		-DGCGI=true
CGI_CXXFLAGS_OFF=	-DGCGI=false

# Currently Ada is only available for x86, so we can assume the following
SF_ARCH=		${ARCH:S/amd64/athlon64/:S/x86_64/athlon64/}
SF_CPU_FLAG=		-march
SF_CFLAGSTYPE=		-DFREEBSD

# shortcuts
SF_SRC=			${WRKSRC}/src
SCAL=			scanner-calendar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL}
CXXFLAGS+=		-DAPQ=true
SETAPQ=			1
.else
CXXFLAGS+=		-DAPQ=false
SETAPQ=			0
.endif
SETMYSQL=	${"${PORT_OPTIONS:MMYSQL}" != "":?1:0}
SETPGSQL=	${"${PORT_OPTIONS:MPGSQL}" != "":?1:0}
SETSOUND=	${"${PORT_OPTIONS:MSOUND}" != "":?1:0}
SETGL=		${"${PORT_OPTIONS:MOPENGL}" != "":?1:0}

post-extract:
	${CP} ${SF_SRC}/bush_freebsd.ads ${SF_SRC}/bush_os.ads
	${CP} ${SF_SRC}/${SCAL}-latest.ads ${SF_SRC}/${SCAL}.ads
	${CP} ${SF_SRC}/${SCAL}-latest.adb ${SF_SRC}/${SCAL}.adb
.if ${SF_ARCH} == "athlon64"
	${CP} ${SF_SRC}/bush_os-sdl-64bit.ads ${SF_SRC}/bush_os-sdl.ads
.else
	${CP} ${SF_SRC}/bush_os-sdl-32bit.ads ${SF_SRC}/bush_os-sdl.ads
.endif
	# Create a compact configure script for ports collection
	${SED} -e "s|@CPU_FLAG@|${SF_CPU_FLAG}|" \
		-e "s|@ARCH@|${SF_ARCH}|" \
		-e "s|@MAKECMD@|${MAKE_CMD}|" \
		-e "s|@CFLAGSTYPE@|${SF_CFLAGSTYPE}|" \
		-e "s|@PREFIX@|${PREFIX}|" \
		-e "s|@SETAPQ@|${SETAPQ}|" \
		-e "s|@SETMYSQL@|${SETMYSQL}|" \
		-e "s|@SETPGSQL@|${SETPGSQL}|" \
		-e "s|@SETSOUND@|${SETSOUND}|" \
		-e "s|@SETGL@|${SETGL}|" \
		-e "s|@SED@|${SED}|" \
		${FILESDIR}/new_configure.in > ${WRKSRC}/new_configure
	${CHMOD} 755 ${WRKSRC}/new_configure

post-patch:
	# Use the gcc compiler associated with the ada frontend.
	# Without this substitution, the base compiler is used instead.
	${REINPLACE_CMD} -e "s|cc |gcc |" ${WRKSRC}/src/pegasock/Makefile
	# Avoid use of malloc.h
	${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|" \
		${WRKSRC}/src/bdb/c_bdb.c
	# Use db.h from db48 and link to it
	# Fix multi-job support
	${REINPLACE_CMD} -e "s|BDB4|BDB4 -I${PREFIX}/include/db48|" \
		-e "s|-ldb|-L${PREFIX}/lib/db48 -ldb|" \
		-e "s|db: db.adb|db: bdb_constants.ads db.adb|" \
		-e "s| -fstack-protector||" \
		${WRKSRC}/src/bdb/GNUmakefile
	# fix areadline linkage
	${REINPLACE_CMD} -e "s|gnatlink.*|gnatlink rl.ali -L${PREFIX}/lib -lreadline -lhistory|" \
		${WRKSRC}/src/areadline/Makefile

post-configure:
.for f in ${PREPFILES}
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
		gnatprep ${CXXFLAGS} ${f}.orig ${f})
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spar

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MV} ${WRKSRC}/examples/incomplete ${WRKDIR}/
	(cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

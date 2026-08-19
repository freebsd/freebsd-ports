PORTNAME=	publisher
DISTVERSIONPREFIX=	v
DISTVERSION=	5.8.0
CATEGORIES=	print

MAINTAINER=	misterd@renderdata.pro
COMMENT=	Non-interactive layout engine and typesetting system ${${FLAVOR}_COMMENT}
WWW=		https://www.speedata.de/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

# Go does not support -buildmode=c-shared on freebsd/arm64 (only on
# freebsd/amd64). See internal/platform/supported.go in the Go source.
# When Go gains arm64 support, the application could also be refactored
# upstream to avoid c-shared entirely.
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	requires Go -buildmode=c-shared, not supported on this architecture

RUN_DEPENDS=	luahbtex:print/tex-luatex

# Flavors: default (community) and pro
FLAVORS=	default pro
FLAVOR?=	${FLAVORS:[1]}

pro_PKGNAMESUFFIX=	-pro
default_COMMENT=	(community)
pro_COMMENT=		(pro)

USES=		go:modules,no_targets lua:53,build,run
USE_GITHUB=	yes
GH_ACCOUNT=	speedata
GH_TUPLE=	\
		Masterminds:semver:v1.5.0:masterminds_semver/src/go/vendor/github.com/Masterminds/semver \
		PuerkitoBio:goquery:v1.9.1:puerkitobio_goquery/src/go/vendor/github.com/PuerkitoBio/goquery \
		alecthomas:chroma:v2.13.0:alecthomas_chroma_v2/src/go/vendor/github.com/alecthomas/chroma/v2 \
		andybalholm:cascadia:v1.3.2:andybalholm_cascadia/src/go/vendor/github.com/andybalholm/cascadia \
		dlclark:regexp2:v1.11.0:dlclark_regexp2/src/go/vendor/github.com/dlclark/regexp2 \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/src/go/vendor/github.com/fsnotify/fsnotify \
		gammazero:deque:v0.2.1:gammazero_deque/src/go/vendor/github.com/gammazero/deque \
		gammazero:workerpool:v1.1.3:gammazero_workerpool/src/go/vendor/github.com/gammazero/workerpool \
		golang:image:v0.39.0:golang_image/src/go/vendor/golang.org/x/image \
		golang:net:v0.53.0:golang_net/src/go/vendor/golang.org/x/net \
		golang:sys:v0.43.0:golang_sys/src/go/vendor/golang.org/x/sys \
		golang:text:v0.36.0:golang_text/src/go/vendor/golang.org/x/text \
		google:btree:v1.1.2:google_btree/src/go/vendor/github.com/google/btree \
		gorilla:mux:v1.8.1:gorilla_mux/src/go/vendor/github.com/gorilla/mux \
		gregjones:httpcache:901d90724c79:gregjones_httpcache/src/go/vendor/github.com/gregjones/httpcache \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/src/go/vendor/github.com/inconshreveable/mousetrap \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/src/go/vendor/github.com/peterbourgon/diskv \
		speedata:bild:dd063a632b14:speedata_bild/src/go/vendor/github.com/speedata/bild \
		speedata:config:3a3f44982ec4:speedata_config/src/go/vendor/github.com/speedata/config \
		speedata:css:68d469dc62c4:speedata_css_scanner/src/go/vendor/github.com/speedata/css \
		speedata:go-lua:v0.1.8:speedata_go_lua/src/go/vendor/github.com/speedata/go-lua \
		speedata:goxlsx:v1.0.2:speedata_goxlsx/src/go/vendor/github.com/speedata/goxlsx \
		speedata:hotfolder:5f743a840a92:speedata_hotfolder/src/go/vendor/github.com/speedata/hotfolder \
		speedata:optionparser:v1.2.1:speedata_optionparser/src/go/vendor/github.com/speedata/optionparser \
		yuin:goldmark-highlighting:37449abec8cc:yuin_goldmark_highlighting_v2/src/go/vendor/github.com/yuin/goldmark-highlighting/v2 \
		yuin:goldmark:v1.7.1:yuin_goldmark/src/go/vendor/github.com/yuin/goldmark

USE_LDCONFIG=	${SP_LIBDIR}

# JAR location for JAVA_TOOLS option (matches what textproc/saxon-he etc. install).
# Not using USES=java so we set this ourselves.
JAVAJARDIR=	${LOCALBASE}/share/java/classes

# Paths compiled into sp binary at build time (final install paths, no STAGEDIR)
SP_LIBDIR=	${PREFIX}/lib/speedata-publisher
SP_SHAREDIR=	${PREFIX}/share/speedata-publisher
SP_SWDIR=	${SP_SHAREDIR}/sw

# pro flavor: pass -X main.pro=yes at link time
.if ${FLAVOR} == pro
SP_LDFLAGS_PRO=	-X main.pro=yes
.else
SP_LDFLAGS_PRO=
.endif

# ldflags for sp binary: compile install paths and version into the binary.
# Set before bsd.port.mk includes go.mk so go.mk's default -ldflags=-s is skipped.
GO_BUILDFLAGS+=	-ldflags="-X main.dest=custom \
		-X main.version=${DISTVERSION} \
		-X main.libdir=${SP_LIBDIR} \
		-X main.srcdir=${SP_SWDIR} \
		${SP_LDFLAGS_PRO} \
		${STRIP}"

# Append Lua include path to CGO_CFLAGS so GO_ENV picks it up
# (don't override CGO_CFLAGS inline; GO_ENV already sets it).
CGO_CFLAGS+=	-I${LUA_INCDIR}

CONFLICTS_INSTALL=	publisher-devel

EXTRACT_AFTER_ARGS=	--exclude lib \
			--no-same-owner --no-same-permissions

# Optional Java helper tools (Saxon for XSLT, Jing for RNG validation,
# Trang for schema conversion). Default ON; turn OFF to manage JARs
# manually (see pkg-help).
OPTIONS_DEFINE=		JAVA_TOOLS
OPTIONS_DEFAULT=	JAVA_TOOLS
OPTIONS_SUB=		yes
JAVA_TOOLS_DESC=	XSLT/RNG support via Saxon, Jing, Trang
JAVA_TOOLS_RUN_DEPENDS=	saxon-he>0:textproc/saxon-he \
			jing>0:textproc/jing \
			trang>0:textproc/trang

# Pre-generated vendor/modules.txt (see files/modules.txt).
# Required because Go 1.21+ needs modules.txt in vendor/, and GH_TUPLE
# extraction does not produce it. Generated on host with: go mod vendor
post-extract:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/src/go/vendor/modules.txt

do-build:
	# libsplib.so -- Go shared library (c-shared mode, CGO uses Lua headers via CGO_CFLAGS)
	# Does not use GO_BUILDFLAGS because that contains sp-specific ldflags.
	(cd ${WRKSRC}/src/go; \
	    ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
	    GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off \
	    ${GO_CMD} build \
	    -buildmode=c-shared \
	    -mod=vendor \
	    -v -trimpath \
	    -buildvcs=false \
	    -ldflags=${STRIP} \
	    -o ${WRKDIR}/libsplib.so \
	    speedatapublisher/splib)

	# luaglue.so -- C glue library
	(cd ${WRKSRC}/src/c; \
	    ${CC} ${CFLAGS} ${CPPFLAGS} -I${LUA_INCDIR} ${LDFLAGS} \
	    -fPIC -shared \
	    -Wl,-soname,luaglue.so \
	    -o ${WRKDIR}/luaglue.so \
	    luaglue.c)

	# sp binary -- dest=custom compiles paths in at link time (via GO_BUILDFLAGS)
	(cd ${WRKSRC}/src/go; \
	    ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
	    GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off \
	    ${GO_CMD} build ${GO_BUILDFLAGS} \
	    -o ${WRKDIR}/sp \
	    speedatapublisher/sp/sp)

do-install:
	# sp binary. 5.6.0+ has fallback logic in getExecutablePath() via the
	# backported patch: sp searches for sdluatex first, then luahbtex.
	# FreeBSD only ships luahbtex, so no symlink is needed.
	${INSTALL_PROGRAM} ${WRKDIR}/sp ${STAGEDIR}${PREFIX}/bin

	# Shared libraries -> ${PREFIX}/lib/speedata-publisher/
	${MKDIR} ${STAGEDIR}${SP_LIBDIR}
	${INSTALL_LIB} ${WRKDIR}/libsplib.so ${WRKDIR}/luaglue.so \
		${STAGEDIR}${SP_LIBDIR}

	# Schema files
	${MKDIR} ${STAGEDIR}${SP_SHAREDIR}/schema
	${INSTALL_DATA} \
		${WRKSRC}/schema/catalog-schema-*.xml \
		${WRKSRC}/schema/layoutschema-*.* \
		${STAGEDIR}${SP_SHAREDIR}/schema

	# Runtime resource files (sw/)
	(cd ${WRKSRC}/src && \
		${COPYTREE_SHARE} "colorprofiles hyphenation lua metapost tex" \
		${STAGEDIR}${SP_SWDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "fonts img" ${STAGEDIR}${SP_SWDIR})

# JAVA_TOOLS option: install a sample config that points sp at the FreeBSD
# JAR location. Requires Publisher 5.5.24+. No symlinks, no version pin.
post-install-JAVA_TOOLS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/speedata
	${ECHO_CMD} "jardir = ${JAVAJARDIR}" > \
	    ${STAGEDIR}${PREFIX}/etc/speedata/publisher.cfg.sample

.include <bsd.port.mk>

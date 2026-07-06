PORTNAME=	publisher
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.3
CATEGORIES=	print

MAINTAINER=	misterd@renderdata.pro
COMMENT=	Non-interactive layout engine and typesetting system ${${FLAVOR}_COMMENT}}
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
		alecthomas:chroma:v0.10.0:alecthomas_chroma/src/go/vendor/github.com/alecthomas/chroma \
		alecthomas:chroma:v2.13.0:alecthomas_chroma_v2/src/go/vendor/github.com/alecthomas/chroma/v2 \
		andybalholm:cascadia:v1.3.2:andybalholm_cascadia/src/go/vendor/github.com/andybalholm/cascadia \
		cjoudrey:gluahttp:25003d9adfa9:cjoudrey_gluahttp/src/go/vendor/github.com/cjoudrey/gluahttp \
		dlclark:regexp2:v1.11.0:dlclark_regexp2/src/go/vendor/github.com/dlclark/regexp2 \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/src/go/vendor/github.com/fsnotify/fsnotify \
		gammazero:deque:v0.2.1:gammazero_deque/src/go/vendor/github.com/gammazero/deque \
		gammazero:workerpool:v1.1.3:gammazero_workerpool/src/go/vendor/github.com/gammazero/workerpool \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/src/go/vendor/gopkg.in/yaml.v3 \
		gofrs:uuid:v4.4.0:gofrs_uuid/src/go/vendor/github.com/gofrs/uuid \
		golang:image:v0.18.0:golang_image/src/go/vendor/golang.org/x/image \
		golang:net:v0.35.0:golang_net/src/go/vendor/golang.org/x/net \
		golang:sys:v0.30.0:golang_sys/src/go/vendor/golang.org/x/sys \
		golang:text:v0.22.0:golang_text/src/go/vendor/golang.org/x/text \
		google:btree:v1.1.2:google_btree/src/go/vendor/github.com/google/btree \
		gorilla:mux:v1.8.1:gorilla_mux/src/go/vendor/github.com/gorilla/mux \
		gregjones:httpcache:901d90724c79:gregjones_httpcache/src/go/vendor/github.com/gregjones/httpcache \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/src/go/vendor/github.com/inconshreveable/mousetrap \
		peterbourgon:diskv:v2.0.1:peterbourgon_diskv/src/go/vendor/github.com/peterbourgon/diskv \
		russross:blackfriday:v1.6.0:russross_blackfriday/src/go/vendor/github.com/russross/blackfriday \
		speedata:bild:dd063a632b14:speedata_bild/src/go/vendor/github.com/speedata/bild \
		speedata:config:3a3f44982ec4:speedata_config/src/go/vendor/github.com/speedata/config \
		speedata:css:68d469dc62c4:speedata_css_scanner/src/go/vendor/github.com/speedata/css \
		speedata:go-epub:v0.5.5:speedata_go_epub/src/go/vendor/github.com/speedata/go-epub \
		speedata:goxlsx:v1.0.2:speedata_goxlsx/src/go/vendor/github.com/speedata/goxlsx \
		speedata:hotfolder:5f743a840a92:speedata_hotfolder/src/go/vendor/github.com/speedata/hotfolder \
		speedata:optionparser:v1.1.1:speedata_optionparser/src/go/vendor/github.com/speedata/optionparser \
		yuin:goldmark-highlighting:37449abec8cc:yuin_goldmark_highlighting_v2/src/go/vendor/github.com/yuin/goldmark-highlighting/v2 \
		yuin:goldmark:v1.7.1:yuin_goldmark/src/go/vendor/github.com/yuin/goldmark \
		yuin:gopher-lua:v1.1.1:yuin_gopher_lua/src/go/vendor/github.com/yuin/gopher-lua

USE_LDCONFIG=	${PREFIX}/lib/speedata-publisher

CONFLICTS_INSTALL=	publisher-devel

# Optional Java helper tools (Saxon for XSLT, Jing for RNG validation,
# Trang for schema conversion). Default ON; turn OFF to manage JARs
# manually (see pkg-message).
OPTIONS_DEFINE=		JAVA_TOOLS
OPTIONS_DEFAULT=	JAVA_TOOLS
OPTIONS_SUB=	yes
JAVA_TOOLS_DESC=	XSLT/RNG support via Saxon, Jing, Trang

JAVA_TOOLS_RUN_DEPENDS=	saxon-he>0:textproc/saxon-he \
			jing>0:textproc/jing \
			trang>0:textproc/trang

# JAR location for JAVA_TOOLS option (matches what textproc/saxon-he etc. install).
# Not using USES=java so we set this ourselves.
JAVAJARDIR=	${LOCALBASE}/share/java/classes

# Append Lua include path to CGO_CFLAGS so GO_ENV picks it up
# (don't override CGO_CFLAGS inline; GO_ENV already sets it).
CGO_CFLAGS+=	-I${LUA_INCDIR}

# Paths compiled into sp binary at build time (final install paths, no STAGEDIR)
SP_LIBDIR=	${PREFIX}/lib/speedata-publisher
SP_SWDIR=	${PREFIX}/share/speedata-publisher/sw
SP_SHAREDIR=	${PREFIX}/share/speedata-publisher

# Pre-generated vendor/modules.txt (see files/modules.txt).
# Required because Go 1.21+ needs modules.txt in vendor/, and GH_TUPLE
# extraction does not produce it. Generated on host with: go mod vendor
post-extract:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/src/go/vendor/modules.txt
	${RM} -r ${WRKSRC}/lib

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
	# sp binary
	${INSTALL_PROGRAM} ${WRKDIR}/sp ${STAGEDIR}${PREFIX}/bin/sp

	# sdluatex symlink to luahbtex (provided by print/tex-luatex at runtime).
	# RLN cannot be used because the target is in a different package and
	# does not exist in our stage dir.
	${LN} -sf ${LOCALBASE}/bin/luahbtex ${STAGEDIR}${PREFIX}/bin/sdluatex

	# Shared libraries -> ${PREFIX}/lib/speedata-publisher/
	${MKDIR} ${STAGEDIR}${SP_LIBDIR}
	${INSTALL_LIB} ${WRKDIR}/libsplib.so ${STAGEDIR}${SP_LIBDIR}/libsplib.so
	${INSTALL_LIB} ${WRKDIR}/luaglue.so ${STAGEDIR}${SP_LIBDIR}/luaglue.so

	# Schema files
	${MKDIR} ${STAGEDIR}${SP_SHAREDIR}/schema
	${INSTALL_DATA} ${WRKSRC}/schema/catalog-schema-de.xml \
	    ${STAGEDIR}${SP_SHAREDIR}/schema/
	${INSTALL_DATA} ${WRKSRC}/schema/catalog-schema-en.xml \
	    ${STAGEDIR}${SP_SHAREDIR}/schema/
	${INSTALL_DATA} ${WRKSRC}/schema/layoutschema-de.rng \
	    ${STAGEDIR}${SP_SHAREDIR}/schema/
	${INSTALL_DATA} ${WRKSRC}/schema/layoutschema-de.xsd \
	    ${STAGEDIR}${SP_SHAREDIR}/schema/
	${INSTALL_DATA} ${WRKSRC}/schema/layoutschema-en.rng \
	    ${STAGEDIR}${SP_SHAREDIR}/schema/
	${INSTALL_DATA} ${WRKSRC}/schema/layoutschema-en.xsd \
	    ${STAGEDIR}${SP_SHAREDIR}/schema/

	# Runtime resource files (sw/)
	${MKDIR} ${STAGEDIR}${SP_SWDIR}
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} lua ${STAGEDIR}${SP_SWDIR})
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} tex ${STAGEDIR}${SP_SWDIR})
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} metapost ${STAGEDIR}${SP_SWDIR})
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} hyphenation ${STAGEDIR}${SP_SWDIR})
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} colorprofiles ${STAGEDIR}${SP_SWDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} fonts ${STAGEDIR}${SP_SWDIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} img ${STAGEDIR}${SP_SWDIR})

# JAVA_TOOLS option: link FreeBSD-provided JARs into the publisher's
# expected paths. sp expects saxon-he-12.9.jar; FreeBSD ships 12.8 which
# is API-compatible (confirmed with upstream). When saxon-he port bumps
# to 12.9 (or later), update the saxon-he line below.
post-install-JAVA_TOOLS-on:
	${MKDIR} ${STAGEDIR}${SP_LIBDIR}/lib
	${LN} -sf ${JAVAJARDIR}/saxon-he-12.8.jar \
	    ${STAGEDIR}${SP_LIBDIR}/saxon-he-12.9.jar
	${LN} -sf ${JAVAJARDIR}/jing.jar \
	    ${STAGEDIR}${SP_LIBDIR}/jing.jar
	${LN} -sf ${JAVAJARDIR}/trang.jar \
	    ${STAGEDIR}${SP_LIBDIR}/trang.jar
	${LN} -sf ${JAVAJARDIR}/xmlresolver-5.3.3.jar \
	    ${STAGEDIR}${SP_LIBDIR}/lib/xmlresolver-5.3.3.jar
	${LN} -sf ${JAVAJARDIR}/xmlresolver-5.3.3-data.jar \
	    ${STAGEDIR}${SP_LIBDIR}/lib/xmlresolver-5.3.3-data.jar

.include <bsd.port.mk>

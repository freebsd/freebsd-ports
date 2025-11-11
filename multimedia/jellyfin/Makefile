PORTNAME=	jellyfin
DISTVERSION=	10.11.2
CATEGORIES=	multimedia
DISTFILES+=	${PREFETCH_FILE}:prefetch
EXTRACT_ONLY+=	${PORTNAME}-${PORTNAME}-${GH_TAGNAME}_GH0.tar.gz \
		${PORTNAME}-${PORTNAME}-web-${GH_TAGNAME}_GH0.tar.gz \
		${PREFETCH_FILE}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Jellyfin Server Component with WebUI
WWW=		https://jellyfin.org/

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

FETCH_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	npm:www/npm${NODEJS_SUFFIX} \
		dotnet:lang/dotnet
LIB_DEPENDS=	libSkiaSharp.so:graphics/libskiasharp
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		ffmpeg>0:multimedia/ffmpeg \
		icu>0:devel/icu \
		krb5>0:security/krb5 \
		libinotify>0:devel/libinotify \
		libunwind>0:devel/libunwind \
		mediainfo>0:multimedia/mediainfo
TEST_DEPENDS=	npm:www/npm${NODEJS_SUFFIX} \
		dotnet:lang/dotnet

USES=		nodejs:24,build sqlite:3 ssl elfctl

USE_GITHUB=	nodefault
GH_ACCOUNT=	jellyfin:server,ui
GH_PROJECT=	jellyfin:server jellyfin-web:ui
GH_SUBDIR=	${PORTNAME}
GH_TAGNAME=	v${DISTVERSION}
USE_RC_SUBR=	jellyfin

NUGET_GROUPS=	NUGET
#NUPKG_NUGET must be regenerated every time DISTVERSION is changed
.include "nupkg_nuget.mk"

SUB_FILES=	jellyfin pkg-message
SUB_LIST=	DATADIR=${LOCALBASE}/jellyfin \
		GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		jellyfin
GROUPS=		jellyfin

DOTNET_ENV=	DOTNET_CLI_HOME=/tmp

#json files must be replaced every time DISTVERSION is updated
PREFETCH_FILE=	${PORTNAME}-${DISTVERSION}-node${NODEJS_VERSION}-modules${EXTRACT_SUFX}
PREFETCH_TIMESTAMP=	61171200
DOTNET_RUNTIME=		${OPSYS:tl}.${OSREL:R}-${ARCH:S|amd64|x64|:C|aarch64|arm64|}

.include "nuget.mk"

pre-fetch:
	@-${_NUGET_FETCH}
	if [ ! -f ${DISTDIR}/${PREFETCH_FILE} ]; then \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${CP} -R ${FILESDIR}/packagejsons/* ${WRKDIR}/node-modules-cache; \
		cd ${WRKDIR}/node-modules-cache && \
		${SETENV} HOME=${WRKDIR} \
			npm ci --ignore-scripts --no-progress --no-audit --no-fund; \
		${FIND} ${WRKDIR}/node-modules-cache -depth 1 -print | \
			${GREP} -v node_modules | ${XARGS} ${RM} -r; \
		${FIND} ${WRKDIR}/node-modules-cache -type d -exec ${CHMOD} 755 {} ';'; \
		cd ${WRKDIR}/node-modules-cache && \
		${MTREE_CMD} -cbnSp node_modules | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./node_modules:' > node-modules-cache.mtree; \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${PREFETCH_FILE} \
			@node-modules-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

post-extract:
	${MV} ${WRKDIR}/node_modules ${WRKSRC_ui}

post-patch:
	${REINPLACE_CMD} -e 's|%%DISTDIR%%|${DISTDIR}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC_server}/nuget.config

do-build:
	cd ${WRKSRC_ui} && ${SETENV} ${MAKE_ENV} \
		npm run build:production

	cd ${WRKSRC_server}/ && \
		${SETENV} ${MAKE_ENV} ${DOTNET_ENV} dotnet restore Jellyfin.Server --runtime ${DOTNET_RUNTIME} --packages ${WRKDIR}/packages && \
		${SETENV} ${MAKE_ENV} ${DOTNET_ENV} dotnet publish Jellyfin.Server --runtime ${DOTNET_RUNTIME} --configuration Release --self-contained --packages ${WRKDIR}/packages -o bin/publish "-p:DebugSymbols=false;DebugType=none;UseAppHost=true;PublishReadyToRun=false"

post-build:
	${MKDIR} ${WRKSRC_server}/bin/publish/jellyfin-web
	${CP} -r ${WRKSRC_ui}/dist/ ${WRKSRC_server}/bin/publish/jellyfin-web

do-install:
	cd ${WRKSRC}/bin/publish/ && ${ELFCTL} -e +noaslr ./jellyfin
	cd ${WRKSRC}/bin/publish/ && ${COPYTREE_SHARE} . ${STAGEDIR}/${LOCALBASE}/jellyfin "! ( -type f -name *\.so -or -type f -name "jellyfin" )"
	cd ${WRKSRC}/bin/publish/ && ${COPYTREE_BIN} . ${STAGEDIR}/${LOCALBASE}/jellyfin " -type f -name "jellyfin" "
	${INSTALL_DATA} ${WRKSRC}/bin/publish/*.so ${STAGEDIR}/${LOCALBASE}/jellyfin

post-install:
	@${ECHO_CMD} "libe_sqlite3.so libsqlite3.so" \
		>${STAGEDIR}${PREFIX}/etc/libmap.d/jellyfin.conf

.include <bsd.port.mk>

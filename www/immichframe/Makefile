PORTNAME=	immichframe
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.39.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/joneum/FreeBSD-Immich/releases/download/immichframe-v${DISTVERSION}/:buildkit
DISTFILES=	immichframe-freebsd-buildkit-${DISTVERSION}${EXTRACT_SUFX}:buildkit \
		immichframe-mk-buildkit.sh:buildkit
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		immichframe-freebsd-buildkit-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Digital photo frame for an Immich library
WWW=		https://github.com/immichFrame/ImmichFrame

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	only amd64 is built and tested

BUILD_DEPENDS=	dotnet8>0:lang/dotnet8 \
		dotnet:lang/dotnet-host \
		${LOCALBASE}/bin/npm:www/npm-node22
RUN_DEPENDS=	dotnet8>0:lang/dotnet8 \
		dotnet:lang/dotnet-host

USES=		nodejs:22,build sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	immichFrame
GH_PROJECT=	ImmichFrame

USE_RC_SUBR=	immichframe

USERS=		immich
GROUPS=		immich

DBDIR=		/var/db/${PORTNAME}
DOTNET_RID=	freebsd-x64

MAKE_ENV=	CI=1 \
		DOTNET_CLI_TELEMETRY_OPTOUT=1 \
		DOTNET_NOLOGO=1 \
		HOME=${WRKDIR} \
		NUGET_PACKAGES=${WRKDIR}/nuget \
		npm_config_cache=${WRKDIR}/npm-cache

SUB_FILES=	immichframe-wrapper immichframe.env pkg-message
PLIST_SUB=	DBDIR="${DBDIR}"

SUB_LIST=	DBDIR=${DBDIR} \
		DOTNET=${LOCALBASE}/bin/dotnet

pre-build:
	@${PRINTF} '%s\n' '<?xml version="1.0" encoding="utf-8"?>' \
		'<configuration>' '  <packageSources>' '    <clear />' \
		'  </packageSources>' '</configuration>' \
		> ${WRKSRC}/NuGet.config

do-build:
	cd ${WRKSRC}/immichFrame.Web && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/npm ci --offline --no-audit --no-fund
	cd ${WRKSRC}/immichFrame.Web && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/npm run build
	cd ${WRKSRC}/ImmichFrame.WebApi && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/dotnet publish --runtime ${DOTNET_RID} \
		--self-contained false -p:AssemblyVersion=${DISTVERSION} \
		-p:DebugType=none -p:DebugSymbols=false \
		-o ${WRKDIR}/out
	@${MKDIR} ${WRKDIR}/out/wwwroot
	cd ${WRKSRC}/immichFrame.Web/build && \
		${PAX} -rw . ${WRKDIR}/out/wwwroot

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${RM} ${WRKDIR}/out/appsettings.Development.json
	cd ${WRKDIR}/out && ${PAX} -rw . ${STAGEDIR}${DATADIR}
	${LN} -s ${LOCALBASE}/lib/libsqlite3.so \
		${STAGEDIR}${DATADIR}/libe_sqlite3.so
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-wrapper \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.env \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.env.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog-immichframe.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/immichframe.conf
	@${MKDIR} ${STAGEDIR}${DBDIR}

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${DATADIR_REL}/wwwroot/_app/immutable -type f | \
		${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>

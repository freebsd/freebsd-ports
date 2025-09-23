PORTNAME=	jellyfin
DISTVERSION=	10.10.7
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
		dotnet:lang/dotnet8
LIB_DEPENDS=	libSkiaSharp.so:graphics/libskiasharp
RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		ffmpeg>0:multimedia/ffmpeg \
		icu>0:devel/icu \
		krb5>0:security/krb5 \
		libinotify>0:devel/libinotify \
		libunwind>0:devel/libunwind \
		mediainfo>0:multimedia/mediainfo
TEST_DEPENDS=	npm:www/npm${NODEJS_SUFFIX} \
		dotnet:lang/dotnet8

USES=		nodejs:22,build sqlite:3 ssl elfctl

USE_GITHUB=	nodefault
GH_ACCOUNT=	jellyfin:server,ui
GH_PROJECT=	jellyfin:server jellyfin-web:ui
GH_SUBDIR=	${PORTNAME}
GH_TAGNAME=	v${DISTVERSION}
USE_RC_SUBR=	jellyfin

NUGET_GROUPS=	NUGET
#NUPKG_NUGET must be regenerated every time DISTVERSION is changed
NUPKG_NUGET=	AsyncKeyedLock:7.0.2 \
AutoFixture.AutoMoq:4.18.1 \
AutoFixture.Xunit2:4.18.1 \
AutoFixture:4.18.1 \
BDInfo:0.8.0 \
BlurHashSharp.SkiaSharp:1.3.4 \
BlurHashSharp:1.3.4 \
CacheManager.Core:1.2.0 \
Castle.Core:5.1.1 \
CommandLineParser:2.9.1 \
Diacritics:3.3.29 \
DiscUtils.Core:0.16.13 \
DiscUtils.Iso9660:0.16.13 \
DiscUtils.Streams:0.16.13 \
DiscUtils.Udf:0.16.13 \
DotNet.Glob:3.1.3 \
EFCoreSecondLevelCacheInterceptor:4.5.0 \
EasyCaching.Core:1.9.2 \
ExCSS:4.2.3 \
FSharp.Core:4.2.3 \
Fare:2.1.1 \
FsCheck.Xunit:2.16.6 \
FsCheck:2.16.6 \
HarfBuzzSharp.NativeAssets.Linux:7.3.0.3 \
HarfBuzzSharp.NativeAssets.Win32:7.3.0.3 \
HarfBuzzSharp.NativeAssets.macOS:7.3.0.3 \
HarfBuzzSharp:7.3.0.3 \
Humanizer.Core:2.14.1 \
ICU4N.Transliterator:60.1.0-alpha.356 \
ICU4N:60.1.0-alpha.356 \
IDisposableAnalyzers:4.0.8 \
J2N:2.0.0 \
Jellyfin.XmlTv:10.8.0 \
LrcParser:2025.228.1 \
MetaBrainz.Common.Json:6.0.2 \
MetaBrainz.Common:3.0.0 \
MetaBrainz.MusicBrainz:6.1.0 \
Microsoft.AspNetCore.Authorization:8.0.11 \
Microsoft.AspNetCore.Http.Abstractions:2.2.0 \
Microsoft.AspNetCore.Http.Extensions:2.2.0 \
Microsoft.AspNetCore.Http.Features:2.2.0 \
Microsoft.AspNetCore.HttpOverrides:2.2.0 \
Microsoft.AspNetCore.Metadata:8.0.11 \
Microsoft.AspNetCore.Mvc.Testing:8.0.4 \
Microsoft.AspNetCore.TestHost:8.0.4 \
Microsoft.Bcl.AsyncInterfaces:6.0.0 \
Microsoft.CodeAnalysis.Analyzers:3.3.3 \
Microsoft.CodeAnalysis.BannedApiAnalyzers:3.3.4 \
Microsoft.CodeAnalysis.CSharp.Workspaces:4.5.0 \
Microsoft.CodeAnalysis.CSharp:4.5.0 \
Microsoft.CodeAnalysis.Common:4.5.0 \
Microsoft.CodeAnalysis.Workspaces.Common:4.5.0 \
Microsoft.CodeCoverage:17.9.0 \
Microsoft.Data.Sqlite.Core:8.0.11 \
Microsoft.Data.Sqlite:8.0.11 \
Microsoft.EntityFrameworkCore.Abstractions:8.0.11 \
Microsoft.EntityFrameworkCore.Analyzers:8.0.11 \
Microsoft.EntityFrameworkCore.Design:8.0.11 \
Microsoft.EntityFrameworkCore.Relational:8.0.11 \
Microsoft.EntityFrameworkCore.Sqlite.Core:8.0.11 \
Microsoft.EntityFrameworkCore.Sqlite:8.0.11 \
Microsoft.EntityFrameworkCore.Tools:8.0.11 \
Microsoft.EntityFrameworkCore:8.0.11 \
Microsoft.Extensions.ApiDescription.Server:3.0.0 \
Microsoft.Extensions.Caching.Abstractions:2.0.0 \
Microsoft.Extensions.Caching.Abstractions:8.0.0 \
Microsoft.Extensions.Caching.Memory:2.0.0 \
Microsoft.Extensions.Caching.Memory:8.0.1 \
Microsoft.Extensions.Configuration.Abstractions:3.1.0 \
Microsoft.Extensions.Configuration.Abstractions:8.0.0 \
Microsoft.Extensions.Configuration.Binder:3.1.0 \
Microsoft.Extensions.Configuration.Binder:8.0.0 \
Microsoft.Extensions.Configuration.Binder:8.0.2 \
Microsoft.Extensions.Configuration.CommandLine:8.0.0 \
Microsoft.Extensions.Configuration.EnvironmentVariables:8.0.0 \
Microsoft.Extensions.Configuration.FileExtensions:8.0.1 \
Microsoft.Extensions.Configuration.Json:8.0.1 \
Microsoft.Extensions.Configuration.UserSecrets:8.0.0 \
Microsoft.Extensions.Configuration:3.1.0 \
Microsoft.Extensions.Configuration:8.0.0 \
Microsoft.Extensions.DependencyInjection.Abstractions:2.0.0 \
Microsoft.Extensions.DependencyInjection.Abstractions:3.1.0 \
Microsoft.Extensions.DependencyInjection.Abstractions:8.0.0 \
Microsoft.Extensions.DependencyInjection.Abstractions:8.0.2 \
Microsoft.Extensions.DependencyInjection:3.1.0 \
Microsoft.Extensions.DependencyInjection:8.0.0 \
Microsoft.Extensions.DependencyInjection:8.0.1 \
Microsoft.Extensions.DependencyModel:8.0.2 \
Microsoft.Extensions.Diagnostics.Abstractions:8.0.0 \
Microsoft.Extensions.Diagnostics.Abstractions:8.0.1 \
Microsoft.Extensions.Diagnostics.HealthChecks.Abstractions:8.0.11 \
Microsoft.Extensions.Diagnostics.HealthChecks.EntityFrameworkCore:8.0.11 \
Microsoft.Extensions.Diagnostics.HealthChecks:8.0.11 \
Microsoft.Extensions.Diagnostics:8.0.1 \
Microsoft.Extensions.FileProviders.Abstractions:8.0.0 \
Microsoft.Extensions.FileProviders.Physical:8.0.0 \
Microsoft.Extensions.FileSystemGlobbing:8.0.0 \
Microsoft.Extensions.Hosting.Abstractions:8.0.0 \
Microsoft.Extensions.Hosting.Abstractions:8.0.1 \
Microsoft.Extensions.Hosting:8.0.0 \
Microsoft.Extensions.Http:3.1.0 \
Microsoft.Extensions.Http:8.0.1 \
Microsoft.Extensions.Logging.Abstractions:3.1.0 \
Microsoft.Extensions.Logging.Abstractions:8.0.0 \
Microsoft.Extensions.Logging.Abstractions:8.0.2 \
Microsoft.Extensions.Logging.Configuration:8.0.0 \
Microsoft.Extensions.Logging.Console:8.0.0 \
Microsoft.Extensions.Logging.Debug:8.0.0 \
Microsoft.Extensions.Logging.EventLog:8.0.0 \
Microsoft.Extensions.Logging.EventSource:8.0.0 \
Microsoft.Extensions.Logging:3.1.0 \
Microsoft.Extensions.Logging:8.0.0 \
Microsoft.Extensions.Logging:8.0.1 \
Microsoft.Extensions.ObjectPool:7.0.0 \
Microsoft.Extensions.Options.ConfigurationExtensions:8.0.0 \
Microsoft.Extensions.Options:2.0.0 \
Microsoft.Extensions.Options:3.1.0 \
Microsoft.Extensions.Options:8.0.0 \
Microsoft.Extensions.Options:8.0.2 \
Microsoft.Extensions.Primitives:2.0.0 \
Microsoft.Extensions.Primitives:3.1.0 \
Microsoft.Extensions.Primitives:8.0.0 \
Microsoft.NET.Test.Sdk:17.9.0 \
Microsoft.NETCore.Platforms:1.1.0 \
Microsoft.NETCore.Platforms:1.1.1 \
Microsoft.NETCore.Platforms:5.0.0 \
Microsoft.NETCore.Targets:1.1.0 \
Microsoft.Net.Http.Headers:2.2.0 \
Microsoft.OpenApi:1.2.3 \
Microsoft.TestPlatform.ObjectModel:17.9.0 \
Microsoft.TestPlatform.TestHost:17.9.0 \
Microsoft.Win32.Primitives:4.3.0 \
Microsoft.Win32.Registry:5.0.0 \
Microsoft.Win32.SystemEvents:8.0.0 \
MimeTypes:2.4.0 \
Mono.Nat:3.0.4 \
Mono.TextTemplating:2.2.1 \
Moq:4.18.4 \
NETStandard.Library:1.6.1 \
NEbml:0.12.0 \
Newtonsoft.Json:13.0.1 \
Newtonsoft.Json:13.0.3 \
PlaylistsNET:1.4.1 \
SQLitePCLRaw.bundle_e_sqlite3:2.1.6 \
SQLitePCLRaw.core:2.1.6 \
SQLitePCLRaw.lib.e_sqlite3:2.1.6 \
SQLitePCLRaw.provider.e_sqlite3:2.1.6 \
Serilog.AspNetCore:8.0.3 \
Serilog.Enrichers.Thread:4.0.0 \
Serilog.Extensions.Hosting:8.0.0 \
Serilog.Extensions.Logging:8.0.0 \
Serilog.Formatting.Compact:2.0.0 \
Serilog.Settings.Configuration:8.0.4 \
Serilog.Sinks.Async:2.1.0 \
Serilog.Sinks.Console:6.0.0 \
Serilog.Sinks.Debug:2.0.0 \
Serilog.Sinks.File:5.0.0 \
Serilog.Sinks.File:6.0.0 \
Serilog.Sinks.Graylog:3.1.1 \
Serilog:3.1.1 \
Serilog:4.0.0 \
Serilog:4.1.0 \
SerilogAnalyzer:0.15.0 \
ShimSkiaSharp:2.0.0.1 \
SkiaSharp.HarfBuzz:2.88.9 \
SkiaSharp.NativeAssets.Linux:2.88.9 \
SkiaSharp.NativeAssets.Win32:2.88.9 \
SkiaSharp.NativeAssets.macOS:2.88.9 \
SkiaSharp:2.88.9 \
SmartAnalyzers.MultithreadingAnalyzer:1.1.31 \
StyleCop.Analyzers.Unstable:1.2.0.556 \
StyleCop.Analyzers:1.2.0-beta.556 \
Svg.Custom:2.0.0.1 \
Svg.Model:2.0.0.1 \
Svg.Skia:2.0.0.1 \
Swashbuckle.AspNetCore.ReDoc:6.5.0 \
Swashbuckle.AspNetCore.Swagger:6.2.3 \
Swashbuckle.AspNetCore.SwaggerGen:6.2.3 \
Swashbuckle.AspNetCore.SwaggerUI:6.2.3 \
Swashbuckle.AspNetCore:6.2.3 \
System.AppContext:4.3.0 \
System.Buffers:4.3.0 \
System.Buffers:4.5.0 \
System.CodeDom:4.4.0 \
System.Collections.Concurrent:4.3.0 \
System.Collections.Immutable:6.0.0 \
System.Collections:4.3.0 \
System.ComponentModel.Annotations:4.3.0 \
System.ComponentModel:4.3.0 \
System.Composition.AttributedModel:6.0.0 \
System.Composition.Convention:6.0.0 \
System.Composition.Hosting:6.0.0 \
System.Composition.Runtime:6.0.0 \
System.Composition.TypedParts:6.0.0 \
System.Composition:6.0.0 \
System.Console:4.0.0 \
System.Console:4.3.0 \
System.Diagnostics.Debug:4.3.0 \
System.Diagnostics.DiagnosticSource:4.3.0 \
System.Diagnostics.DiagnosticSource:8.0.0 \
System.Diagnostics.EventLog:8.0.0 \
System.Diagnostics.Tools:4.3.0 \
System.Diagnostics.Tracing:4.3.0 \
System.Drawing.Common:8.0.8 \
System.Globalization.Calendars:4.3.0 \
System.Globalization.Extensions:4.3.0 \
System.Globalization:4.0.11 \
System.Globalization:4.3.0 \
System.IO.Compression.ZipFile:4.3.0 \
System.IO.Compression:4.3.0 \
System.IO.FileSystem.Primitives:4.3.0 \
System.IO.FileSystem:4.3.0 \
System.IO.Hashing:8.0.0 \
System.IO.Pipelines:6.0.3 \
System.IO.Pipelines:8.0.0 \
System.IO:4.1.0 \
System.IO:4.3.0 \
System.Linq.Async:6.0.1 \
System.Linq.Expressions:4.3.0 \
System.Linq.Queryable:4.0.1 \
System.Linq:4.3.0 \
System.Memory:4.5.3 \
System.Net.Http:4.3.4 \
System.Net.Primitives:4.0.11 \
System.Net.Primitives:4.3.0 \
System.Net.Requests:4.0.11 \
System.Net.Sockets:4.3.0 \
System.Net.WebHeaderCollection:4.0.1 \
System.ObjectModel:4.0.12 \
System.ObjectModel:4.3.0 \
System.Private.Uri:4.3.0 \
System.Reflection.Emit.ILGeneration:4.3.0 \
System.Reflection.Emit.Lightweight:4.3.0 \
System.Reflection.Emit:4.3.0 \
System.Reflection.Extensions:4.3.0 \
System.Reflection.Metadata:6.0.1 \
System.Reflection.Primitives:4.3.0 \
System.Reflection.TypeExtensions:4.3.0 \
System.Reflection:4.3.0 \
System.Resources.ResourceManager:4.3.0 \
System.Runtime.CompilerServices.Unsafe:4.4.0 \
System.Runtime.CompilerServices.Unsafe:6.0.0 \
System.Runtime.Extensions:4.3.0 \
System.Runtime.Handles:4.3.0 \
System.Runtime.InteropServices.RuntimeInformation:4.3.0 \
System.Runtime.InteropServices:4.3.0 \
System.Runtime.Numerics:4.3.0 \
System.Runtime:4.3.0 \
System.Security.AccessControl:5.0.0 \
System.Security.Cryptography.Algorithms:4.3.0 \
System.Security.Cryptography.Cng:4.3.0 \
System.Security.Cryptography.Csp:4.3.0 \
System.Security.Cryptography.Encoding:4.3.0 \
System.Security.Cryptography.OpenSsl:4.3.0 \
System.Security.Cryptography.Primitives:4.3.0 \
System.Security.Cryptography.X509Certificates:4.3.0 \
System.Security.Principal.Windows:5.0.0 \
System.Text.Encoding.CodePages:6.0.0 \
System.Text.Encoding.CodePages:8.0.0 \
System.Text.Encoding.Extensions:4.3.0 \
System.Text.Encoding:4.3.0 \
System.Text.Encodings.Web:8.0.0 \
System.Text.Json:8.0.5 \
System.Text.RegularExpressions:4.3.0 \
System.Threading.Channels:6.0.0 \
System.Threading.Tasks.Dataflow:8.0.1 \
System.Threading.Tasks.Extensions:4.3.0 \
System.Threading.Tasks.Parallel:4.0.1 \
System.Threading.Tasks:4.3.0 \
System.Threading.Thread:4.0.0 \
System.Threading.ThreadPool:4.0.10 \
System.Threading.Timer:4.3.0 \
System.Threading:4.3.0 \
System.Xml.ReaderWriter:4.3.0 \
System.Xml.XDocument:4.3.0 \
TMDbLib:2.2.0 \
TagLibSharp:2.3.0 \
UTF.Unknown:2.5.1 \
Validation:2.4.18 \
Xunit.Priority:1.1.6 \
Xunit.SkippableFact:1.4.13 \
coverlet.collector:6.0.2 \
libse:4.0.8 \
prometheus-net.AspNetCore:8.2.1 \
prometheus-net.DotNetRuntime:4.4.1 \
prometheus-net:3.1.2 \
prometheus-net:8.2.1 \
runtime.debian.8-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.fedora.23-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.fedora.24-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.native.System.IO.Compression:4.3.0 \
runtime.native.System.Net.Http:4.0.1 \
runtime.native.System.Net.Http:4.3.0 \
runtime.native.System.Security.Cryptography.Apple:4.3.0 \
runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.native.System.Security.Cryptography:4.0.0 \
runtime.native.System:4.3.0 \
runtime.opensuse.13.2-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.opensuse.42.1-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.osx.10.10-x64.runtime.native.System.Security.Cryptography.Apple:4.3.0 \
runtime.osx.10.10-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.rhel.7-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.ubuntu.14.04-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.ubuntu.16.04-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
runtime.ubuntu.16.10-x64.runtime.native.System.Security.Cryptography.OpenSsl:4.3.2 \
xunit.abstractions:2.0.3 \
xunit.analyzers:1.12.0 \
xunit.assert:2.7.1 \
xunit.core:2.7.1 \
xunit.extensibility.core:2.7.1 \
xunit.extensibility.execution:2.7.1 \
xunit.runner.visualstudio:2.5.8 \
xunit:2.7.1 \
zlib.net-mutliplatform:1.0.8 \
runtime.any.system.collections:4.3.0 \
runtime.any.system.diagnostics.tracing:4.3.0 \
runtime.any.system.globalization:4.3.0 \
runtime.any.system.globalization.calendars:4.3.0 \
runtime.any.system.io:4.3.0 \
runtime.any.system.reflection:4.3.0 \
runtime.any.system.reflection.extensions:4.3.0 \
runtime.any.system.reflection.primitives:4.3.0 \
runtime.any.system.resources.resourcemanager:4.3.0 \
runtime.any.system.runtime:4.3.0 \
runtime.any.system.runtime.handles:4.3.0 \
runtime.any.system.runtime.interopservices:4.3.0 \
runtime.any.system.text.encoding:4.3.0 \
runtime.any.system.text.encoding.extensions:4.3.0 \
runtime.any.system.threading.tasks:4.3.0 \
runtime.unix.microsoft.win32.primitives:4.3.0 \
runtime.unix.system.diagnostics.debug:4.3.0 \
runtime.unix.system.io.filesystem:4.3.0 \
runtime.unix.system.net.primitives:4.3.0 \
runtime.unix.system.private.uri:4.3.0 \
runtime.unix.system.runtime.extensions:4.3.0 \
z440.atl.core:6.20.0 \
Ude.NetStandard:1.2.0 \

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
		${SETENV} ${MAKE_ENV} ${DOTNET_ENV} dotnet restore Jellyfin.Server --runtime freebsd-x64 --packages ${WRKDIR}/packages && \
		${SETENV} ${MAKE_ENV} ${DOTNET_ENV} dotnet publish Jellyfin.Server --configuration Release --self-contained --runtime freebsd-x64 --packages ${WRKDIR}/packages -o bin/publish "-p:DebugSymbols=false;DebugType=none;UseAppHost=true;PublishReadyToRun=false"

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

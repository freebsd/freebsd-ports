PORTNAME=	powershell
DISTVERSIONPREFIX=v
DISTVERSION=	7.5.2
CATEGORIES=	shells

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Microsoft's shell with support for .NET objects
WWW=		https://microsoft.com/PowerShell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	dotnet>=9.0.6:lang/dotnet
LIB_DEPENDS=	libbrotlienc.so:archivers/brotli \
		libinotify.so:devel/libinotify \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	dotnet:lang/dotnet-host \
		terminfo-db>0:misc/terminfo-db \
		${LOCALBASE}/lib/powershell/libpsl-native.so:shells/libpowershell-native \
		${LOCALBASE}/lib/libicuuc.so:devel/icu

USES=		gssapi:mit ssl:run

USE_GITHUB=	yes
GH_ACCOUNT=	PowerShell
GH_PROJECT=	PowerShell

DOTNET_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/}

NUGET_GROUPS=	NUGET PWSH
NUGET_NUPKGS=	DotNetAnalyzers.DocumentationAnalyzers:1.0.0-beta.59 \
		DotNetAnalyzers.DocumentationAnalyzers.Unstable:1.0.0.59 \
		JetBrains.Annotations:2021.2.0 \
		Json.More.Net:2.0.2 \
		JsonPointer.Net:5.0.2 \
		JsonSchema.Net:7.2.3 \
		Markdig.Signed:0.38.0 \
		Microsoft.ApplicationInsights:2.22.0 \
		Microsoft.Bcl.AsyncInterfaces:8.0.0 \
		Microsoft.CodeAnalysis.Analyzers:3.11.0 \
		Microsoft.CodeAnalysis.Common:4.11.0 \
		Microsoft.CodeAnalysis.CSharp:4.11.0 \
		Microsoft.Extensions.ObjectPool:8.0.17 \
		Microsoft.Management.Infrastructure:3.0.0 \
		Microsoft.Management.Infrastructure.Runtime.Unix:3.0.0 \
		Microsoft.Management.Infrastructure.Runtime.Win:3.0.0 \
		Microsoft.NETCore.Platforms:7.0.4 \
		Microsoft.PowerShell.MarkdownRender:7.2.1 \
		Microsoft.PowerShell.Native:7.4.0 \
		Microsoft.Security.Extensions:1.4.0 \
		Microsoft.Win32.Registry:5.0.0 \
		Microsoft.Win32.Registry.AccessControl:9.0.6 \
		Microsoft.Win32.SystemEvents:9.0.6 \
		Microsoft.Windows.Compatibility:9.0.6 \
		NETStandard.Library:2.0.3 \
		Newtonsoft.Json:13.0.3 \
		runtime.linux-arm.runtime.native.System.IO.Ports:9.0.6 \
		runtime.linux-arm64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.linux-x64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.android-arm.runtime.native.System.IO.Ports:9.0.6 \
		runtime.android-arm64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.android-x64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.android-x86.runtime.native.System.IO.Ports:9.0.6 \
		runtime.linux-bionic-arm64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.linux-bionic-x64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.linux-musl-arm.runtime.native.System.IO.Ports:9.0.6 \
		runtime.linux-musl-arm64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.linux-musl-x64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.maccatalyst-arm64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.maccatalyst-x64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.native.System.IO.Ports:9.0.6 \
		runtime.osx-arm64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.osx-x64.runtime.native.System.IO.Ports:9.0.6 \
		runtime.win-arm64.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.win-x64.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.win-x86.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		StyleCop.Analyzers:1.2.0-beta.556 \
		StyleCop.Analyzers.Unstable:1.2.0.556 \
		System.Buffers:4.5.1 \
		System.CodeDom:9.0.6 \
		System.Collections.Immutable:9.0.6 \
		System.Collections.Immutable:8.0.0 \
		System.ComponentModel.Composition:9.0.6 \
		System.ComponentModel.Composition.Registration:9.0.6 \
		System.Configuration.ConfigurationManager:9.0.6 \
		System.Data.Odbc:9.0.6 \
		System.Data.OleDb:9.0.6 \
		System.Data.SqlClient:4.9.0 \
		System.Diagnostics.DiagnosticSource:9.0.6 \
		System.Diagnostics.EventLog:9.0.6 \
		System.Diagnostics.PerformanceCounter:9.0.6 \
		System.DirectoryServices:9.0.6 \
		System.DirectoryServices.AccountManagement:9.0.6 \
		System.DirectoryServices.Protocols:9.0.6 \
		System.Drawing.Common:9.0.6 \
		System.Formats.Asn1:6.0.0 \
		System.IO.Packaging:9.0.6 \
		System.IO.Ports:9.0.6 \
		System.Management:9.0.6 \
		System.Memory:4.5.5 \
		System.Net.Http.WinHttpHandler:9.0.6 \
		System.Numerics.Vectors:4.4.0 \
		System.Numerics.Vectors:4.5.0 \
		System.Private.ServiceModel:4.10.3 \
		System.Reflection.Context:9.0.6 \
		System.Reflection.DispatchProxy:4.7.1 \
		System.Reflection.Metadata:8.0.1 \
		System.Runtime.Caching:9.0.6 \
		System.Runtime.CompilerServices.Unsafe:6.0.0 \
		System.Security.AccessControl:6.0.1 \
		System.Security.Cryptography.Pkcs:9.0.6 \
		System.Security.Cryptography.ProtectedData:9.0.6 \
		System.Security.Cryptography.Xml:9.0.6 \
		System.Security.Permissions:9.0.6 \
		System.Security.Principal.Windows:5.0.0 \
		System.ServiceModel.Duplex:4.10.3 \
		System.ServiceModel.Http:4.10.3 \
		System.ServiceModel.NetTcp:4.10.3 \
		System.ServiceModel.Primitives:4.10.3 \
		System.ServiceModel.Security:4.10.3 \
		System.ServiceModel.Syndication:9.0.6 \
		System.ServiceProcess.ServiceController:9.0.6 \
		System.Speech:9.0.6 \
		System.Text.Encoding.CodePages:7.0.0 \
		System.Text.Encoding.CodePages:8.0.0 \
		System.Text.Encoding.CodePages:9.0.6 \
		System.Text.Encodings.Web:6.0.0 \
		System.Text.Encodings.Web:9.0.6 \
		System.Text.Json:6.0.9 \
		System.Threading.AccessControl:9.0.6 \
		System.Threading.Tasks.Extensions:4.5.4 \
		System.Web.Services.Description:8.0.0 \
		System.Windows.Extensions:9.0.6 \
		Humanizer.Core:2.14.1
PWSH_NUPKGS=	Microsoft.PowerShell.PSResourceGet:1.0.3 \
		PSReadLine:2.3.4 \
		PowerShellGet:3.0.23-beta23

PWSH_MOD_EXTRACT_ARGS=	-x "\[Content_Types\].xml" \
			-x "_*/*" \
			-x "package/*" \
			-x "*.txt" \
			-x "*.nuspec"

DOTNET_CMD=	${SETENV} HOME=${WRKDIR} ${LOCALBASE}/bin/dotnet

post-extract:
	${MKDIR} ${WRKSRC}/src/Microsoft.PowerShell.SDK/obj
	${CP} ${FILESDIR}/Microsoft.PowerShell.SDK.csproj.TypeCatalog.targets \
		${WRKSRC}/src/Microsoft.PowerShell.SDK/obj

post-patch:
	${REINPLACE_CMD} -e 's|%%NUGET_DISTDIR%%|${DISTDIR}/${NUGET_DISTSUBDIR}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/nuget.config
	${REINPLACE_CMD} -e 's|9.0.301|9.0.107|' ${WRKSRC}/global.json

do-build:
	cd ${WRKSRC}/src/ResGen && \
		${DOTNET_CMD} restore --packages ${WRKDIR}/packages && \
		${DOTNET_CMD} build --no-restore && \
		${DOTNET_CMD} run --no-restore
	cd ${WRKSRC}/src/powershell-unix && \
		${DOTNET_CMD} restore --packages ${WRKDIR}/packages
	cd ${WRKSRC}/src && \
		${DOTNET_CMD} msbuild \
			Microsoft.PowerShell.SDK/Microsoft.PowerShell.SDK.csproj \
			/t:_GetDependencies \
			/p:DesignTimeBuild=true \
			/p:_DependencyFile=${WRKSRC}/src/TypeCatalogGen/powershell.inc \
			/nologo
	cd ${WRKSRC}/src/TypeCatalogGen && \
		${DOTNET_CMD} restore --packages ${WRKDIR}/packages && \
		${DOTNET_CMD} dotnet build --no-restore && \
		${DOTNET_CMD} run --no-restore \
			../System.Management.Automation/CoreCLR/CorePsTypeCatalog.cs \
			powershell.inc
	cd ${WRKSRC}/src/powershell-unix && \
		${DOTNET_CMD} publish --packages ${WRKDIR}/packages -c Release \
			-r freebsd.${_OSVERSION_MAJOR}-${DOTNET_ARCH} -o bin/publish \
			--sc -p:PublishReadyToRun=false

do-install:
	${CP} -r ${WRKSRC}/src/powershell-unix/bin/publish \
		${STAGEDIR}${PREFIX}/lib/powershell
	${LN} -s ../lib/powershell/pwsh ${STAGEDIR}${PREFIX}/bin

post-install:
.for m in ${PWSH_NUPKGS}
	${UNZIP_NATIVE_CMD} ${PWSH_MOD_EXTRACT_ARGS} \
		-d ${STAGEDIR}${PREFIX}/lib/powershell/Modules/${m:C/:.*//} \
		${DISTDIR}/nuget/${m:C/:.*//:tl}.${m:C/.*://:tl}.nupkg
.endfor

.include "nuget.mk"
.include <bsd.port.mk>

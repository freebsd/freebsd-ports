PORTNAME=	powershell
DISTVERSIONPREFIX=v
DISTVERSION=	7.5.4
CATEGORIES=	shells

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Microsoft's shell with support for .NET objects
WWW=		https://microsoft.com/PowerShell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	dotnet>=${DOTNET_VER}:lang/dotnet
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

DOTNET_VER=	9.0.10
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
		Microsoft.Extensions.ObjectPool:8.0.21 \
		Microsoft.Management.Infrastructure:3.0.0 \
		Microsoft.Management.Infrastructure.Runtime.Unix:3.0.0 \
		Microsoft.Management.Infrastructure.Runtime.Win:3.0.0 \
		Microsoft.NETCore.Platforms:7.0.4 \
		Microsoft.PowerShell.MarkdownRender:7.2.1 \
		Microsoft.PowerShell.Native:7.4.0 \
		Microsoft.Security.Extensions:1.4.0 \
		Microsoft.Win32.Registry:5.0.0 \
		Microsoft.Win32.Registry.AccessControl:${DOTNET_VER} \
		Microsoft.Win32.SystemEvents:${DOTNET_VER} \
		Microsoft.Windows.Compatibility:${DOTNET_VER} \
		NETStandard.Library:2.0.3 \
		Newtonsoft.Json:13.0.4 \
		runtime.linux-arm.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.linux-arm64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.linux-x64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.android-arm.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.android-arm64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.android-x64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.android-x86.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.linux-bionic-arm64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.linux-bionic-x64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.linux-musl-arm.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.linux-musl-arm64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.linux-musl-x64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.maccatalyst-arm64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.maccatalyst-x64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.osx-arm64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.osx-x64.runtime.native.System.IO.Ports:${DOTNET_VER} \
		runtime.win-arm64.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.win-x64.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		runtime.win-x86.runtime.native.System.Data.SqlClient.sni:4.4.0 \
		StyleCop.Analyzers:1.2.0-beta.556 \
		StyleCop.Analyzers.Unstable:1.2.0.556 \
		System.Buffers:4.5.1 \
		System.CodeDom:${DOTNET_VER} \
		System.Collections.Immutable:${DOTNET_VER} \
		System.Collections.Immutable:8.0.0 \
		System.ComponentModel.Composition:${DOTNET_VER} \
		System.ComponentModel.Composition.Registration:${DOTNET_VER} \
		System.Configuration.ConfigurationManager:${DOTNET_VER} \
		System.Data.Odbc:${DOTNET_VER} \
		System.Data.OleDb:${DOTNET_VER} \
		System.Data.SqlClient:4.9.0 \
		System.Diagnostics.DiagnosticSource:${DOTNET_VER} \
		System.Diagnostics.EventLog:${DOTNET_VER} \
		System.Diagnostics.PerformanceCounter:${DOTNET_VER} \
		System.DirectoryServices:${DOTNET_VER} \
		System.DirectoryServices.AccountManagement:${DOTNET_VER} \
		System.DirectoryServices.Protocols:${DOTNET_VER} \
		System.Drawing.Common:${DOTNET_VER} \
		System.Formats.Asn1:6.0.0 \
		System.IO.Packaging:${DOTNET_VER} \
		System.IO.Ports:${DOTNET_VER} \
		System.Management:${DOTNET_VER} \
		System.Memory:4.5.5 \
		System.Net.Http.WinHttpHandler:${DOTNET_VER} \
		System.Numerics.Vectors:4.4.0 \
		System.Numerics.Vectors:4.5.0 \
		System.Private.ServiceModel:4.10.3 \
		System.Reflection.Context:${DOTNET_VER} \
		System.Reflection.DispatchProxy:4.7.1 \
		System.Reflection.Metadata:8.0.1 \
		System.Runtime.Caching:${DOTNET_VER} \
		System.Runtime.CompilerServices.Unsafe:6.0.0 \
		System.Security.AccessControl:6.0.1 \
		System.Security.Cryptography.Pkcs:${DOTNET_VER} \
		System.Security.Cryptography.ProtectedData:${DOTNET_VER} \
		System.Security.Cryptography.Xml:${DOTNET_VER} \
		System.Security.Permissions:${DOTNET_VER} \
		System.Security.Principal.Windows:5.0.0 \
		System.ServiceModel.Duplex:4.10.3 \
		System.ServiceModel.Http:4.10.3 \
		System.ServiceModel.NetTcp:4.10.3 \
		System.ServiceModel.Primitives:4.10.3 \
		System.ServiceModel.Security:4.10.3 \
		System.ServiceModel.Syndication:${DOTNET_VER} \
		System.ServiceProcess.ServiceController:${DOTNET_VER} \
		System.Speech:${DOTNET_VER} \
		System.Text.Encoding.CodePages:7.0.0 \
		System.Text.Encoding.CodePages:8.0.0 \
		System.Text.Encoding.CodePages:${DOTNET_VER} \
		System.Text.Encodings.Web:6.0.0 \
		System.Text.Encodings.Web:${DOTNET_VER} \
		System.Text.Json:6.0.9 \
		System.Threading.AccessControl:${DOTNET_VER} \
		System.Threading.Tasks.Extensions:4.5.4 \
		System.Web.Services.Description:8.0.0 \
		System.Windows.Extensions:${DOTNET_VER} \
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
	${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' \
		${WRKSRC}/PowerShell.Common.props
	${REINPLACE_CMD} -e 's|9.0.306|9.0.111|' ${WRKSRC}/global.json

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

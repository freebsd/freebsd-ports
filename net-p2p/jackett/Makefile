PORTNAME=	jackett
DISTVERSIONPREFIX=	v
DISTVERSION=	0.22.2311
CATEGORIES=	net-p2p

MAINTAINER=	tremere@cainites.net
COMMENT=	Torznab proxy implementation of the Newznab API
WWW=		https://github.com/Jackett/Jackett

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dotnet>=9.0.6:lang/dotnet
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libinotify.so:devel/libinotify \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	${LOCALBASE}/lib/libicuuc.so:devel/icu \
		dotnet:lang/dotnet-host

USES=		gssapi:mit ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Jackett
GH_PROJECT=	Jackett
USE_RC_SUBR=	jackett

USERS=		jackett
GROUPS=		jackett

DOTNET_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/}

DOTNET_CMD=	${SETENV} HOME=${WRKDIR} ${LOCALBASE}/bin/dotnet

.include "Makefile.nuget"
.include "../../shells/powershell/nuget.mk"

post-patch:
	${REINPLACE_CMD} "s/0.0.0/${DISTVERSION}/" \
		${WRKSRC}/src/Jackett.Common/Jackett.Common.csproj
	${REINPLACE_CMD} "s/net8.0/net9.0/g" \
		${WRKSRC}/src/Jackett.Server/Jackett.Server.csproj

do-build:
	cd ${WRKSRC}/src && \
	${DOTNET_CMD} nuget add source ${DISTDIR}/nuget && \
	${DOTNET_CMD} nuget disable source nuget.org && \
	${DOTNET_CMD} restore Jackett.Server -s ${DISTDIR}/nuget --packages ${WRKDIR}/packages && \
	${DOTNET_CMD} publish Jackett.Server -f net9.0 -c Release \
		-r freebsd.${_OSVERSION_MAJOR}-${DOTNET_ARCH} --sc -p:PublishReadyToRun=false -o bin/publish

do-install:
	cd ${WRKSRC}/src/bin/publish && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR} "! -name jackett"
	${INSTALL_PROGRAM} ${WRKSRC}/src/bin/publish/jackett ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>

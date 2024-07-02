PORTNAME=	powershell
DISTVERSIONPREFIX=      v
DISTVERSION=	7.4.0
CATEGORIES=	shells

COMMENT=	powershell

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	PowerShell
GH_PROJECT=	PowerShell
#GH_TAGNAME=	9da657e3a80e0fb6fdad4fc7da8d5d48ae2a5c2a

USES=	cmake linux
DISTFILES += powershell-${DISTVERSION}-linux-x64.tar.gz:github
#https://github.com/PowerShell/PowerShell/releases/download/v${DISTVERSION}/powershell-${DISTVERSION}-linux-x64.tar.gz

post-patch:
		@${REINPLACE_CMD} -e 's|git describe --abbrev=60 --long|echo v${DISTVERSION}-0-g0|g' ${WRKSRC}/PowerShell.Common.props


build:
	cd ${WRKSRC} && ../pwsh -c 'Import-Module ./build.psm1 -ArgumentList $$true; Start-PSBuild'

.include <bsd.port.mk>

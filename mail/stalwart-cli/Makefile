PORTNAME=	stalwart-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.12
CATEGORIES=	mail

MAINTAINER=	orville@anislet.dev
COMMENT=	Stalwart Mail Server CLI
WWW=		https://stalw.art/

LICENSE=		AGPLv3 SELv2
LICENSE_COMB=		multi
LICENSE_NAME_SELv2=	Stalwart Enterprise License 2.0
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSES/AGPL-3.0-only.txt
LICENSE_FILE_SELv2=	${WRKSRC}/LICENSES/LicenseRef-SEL.txt
LICENSE_PERMS_SELv2=	pkg-mirror auto-accept

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	stalwartlabs
GH_PROJECT=	cli

PLIST_FILES=	bin/stalwart-cli

.include <bsd.port.mk>

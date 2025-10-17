PORTNAME=	httm
DISTVERSION=	0.48.2
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Dream of a CLI Time Machine
WWW=		https://github.com/kimono-koans/httm

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Fails to build: non-binding let on a synchronization lock

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kimono-koans

PLIST_FILES=	bin/httm

OPTIONS_DEFINE=	SCRIPTS
OPTIONS_DEFAULT=SCRIPTS

SCRIPTS_DESC=	Install example scripts

SCRIPTS_RUN_DEPENDS=	bash:shells/bash
SCRIPTS_PLIST_FILES=	bin/bowie

post-install-SCRIPTS-on:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/bowie.bash ${STAGEDIR}${PREFIX}/bin/bowie

.include <bsd.port.mk>

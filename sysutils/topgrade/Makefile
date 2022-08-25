PORTNAME=	topgrade
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.1
CATEGORIES=	sysutils

MAINTAINER=	freebsd@scd-systems.net
COMMENT=	Tool for upgrade everything

LICENSE=	GPLv3

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	failed to run custom build command for `sys-info v0.9.1`

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	r-darwish

PLIST_FILES=	bin/topgrade \
		man/man8/topgrade.8.gz
PORTEXAMPLES=	config.example.toml

OPTIONS_DEFINE=	EXAMPLES

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${INSTALL_MAN} ${WRKSRC}/topgrade.8 ${STAGEDIR}${PREFIX}/man/man8/

post-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

PORTNAME=	mod_evasive
PORTVERSION=	2.4.0
CATEGORIES=	www security
DIST_SUBDIR=	apache24

MAINTAINER=	devnull@apt322.org
COMMENT=	Apache evasive maneuvers module to protect HTTP Server from DoS attack
WWW=		https://github.com/jvdmr/mod_evasive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		apache shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	jvdmr
GH_PROJECT=	mod_evasive
GH_TAGNAME=	7385d78146a5e23f953e6566c8e29d8ae36e00ad

SHEBANG_FILES=	test

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
MODULENAME=	mod_evasive

PORTDOCS=	README.md
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/mail|/usr/bin/mail|g" ${WRKSRC}/mod_evasive24.c
	@${MV} ${WRKSRC}/mod_evasive24.c ${WRKSRC}/mod_evasive.c
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/99_regular_config_pf/
	cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/99_regular_config_pf/*.conf ${STAGEDIR}${EXAMPLESDIR}/99_regular_config_pf/

.include <bsd.port.mk>

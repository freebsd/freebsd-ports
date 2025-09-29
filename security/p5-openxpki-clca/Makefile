PORTNAME=	openxpki-clca
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Toolkit for basic PKI operations in small CA like root CA

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	bash:shells/bash \
		p5-Class-Std>=0:devel/p5-Class-Std \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-YAML>=0:textproc/p5-YAML
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5 shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
GH_PROJECT=	clca
SHEBANG_FILES=	bin/*

NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	skipv:^v?1\.[0-9] # Ignore ancient versions
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

pre-configure:
	@${ECHO} "Patching dir names...";
# shebangfix does not help in the middle of files:
	${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|g" ${WRKSRC}/bin/clca
	${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|g" \
		${WRKSRC}/README.keyceremony-shared-interactive.md

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/clca ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/change-quorum.sh ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "bin etc lib" ${STAGEDIR}${EXAMPLESDIR} \
		"! -name *\.orig ! -name *\.bak")

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-name *\.md")

.include <bsd.port.mk>

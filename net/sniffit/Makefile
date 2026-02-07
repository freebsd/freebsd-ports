PORTNAME=	sniffit
DISTVERSION=	0.7
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Packet sniffer program. For educational use

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf cpe
CPE_VENDOR=	sniffit_project
USE_GITHUB=	yes
GH_ACCOUNT=	resurrecting-open-source-projects

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sniffit ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/sniffit.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/sniffit.8 ${STAGEDIR}${PREFIX}/share/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/PLUGIN-HOWTO   ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README.FIRST ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/UPDATE-CHECK ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/sniffit-FAQ ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/sample_config_file ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

# Created by: bsdx
# $FreeBSD$

PORTNAME=	sniffit
PORTVERSION=	0.5
CATEGORIES=	net security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet sniffer program. For educational use

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	resurrecting-open-source-projects
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sniffit ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/sniffit.5 ${STAGEDIR}${MANPREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/sniffit.8 ${STAGEDIR}${MANPREFIX}/share/man/man8

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

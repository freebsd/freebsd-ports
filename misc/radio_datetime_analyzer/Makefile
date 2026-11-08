PORTNAME=	radio_datetime_analyzer
DISTVERSION=	1.2.0
PORTREVISION=	10
CATEGORIES=	misc
FJ_ACCOUNT=	rene0

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Analyzer for DCF77 and MSF log files

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

USES=		cargo
USE_FORGEJO=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	bin/radio_datetime_analyzer
PORTDOCS=	README.md
PORTEXAMPLES=	edge-999.log sample_dcf77.log sample_msf.log

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/src/transmitters/test/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

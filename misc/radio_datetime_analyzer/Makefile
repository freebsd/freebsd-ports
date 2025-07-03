PORTNAME=	radio_datetime_analyzer
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://codeberg.org/rene0/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} # prevent USES=cargo from overriding default DISTFILES

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Analyzer for DCF77 and MSF log files
WWW=		https://codeberg.org/rene0/${PORTNAME}

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

USES=		cargo
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	bin/radio_datetime_analyzer
PORTDOCS=	README.md
PORTEXAMPLES=	sample_dcf77.log sample_msf.log

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in sample_dcf77.log sample_msf.log
	${INSTALL_DATA} ${WRKSRC}/src/transmitters/test/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>

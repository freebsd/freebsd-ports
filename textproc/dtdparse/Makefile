# New ports collection makefile for:   dtdparse
# Date created:                29 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtdparse
PORTVERSION=	2.0.b6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dtdparse
DISTNAME=       ${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER=	fuyuki@mj.0038.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Text/DelimMatch.pm:${PORTSDIR}/textproc/p5-DelimMatch \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

USE_PERL5=	yes

NO_BUILD=	yes

SITE_PERL=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}
XMLDIR=		${PREFIX}/share/xml/${PORTNAME}

SCRIPTS=	dtdflatten dtdformat dtdparse \
		tools/contentmodel tools/dtdstats tools/elements

MKCATALOG=	${LOCALBASE}/sbin/mkcatalog
PLIST_SUB=	MKCATALOG=${MKCATALOG}

post-patch:
	cd ${WRKSRC}; \
		${PERL} -pi -e 's,/usr/local/bin/perl5,${PERL},' ${SCRIPTS}

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	${MKDIR} ${SITE_PERL}/XML/DTDParse
	${INSTALL_DATA} ${WRKSRC}/XML/DTDParse/*.pm ${SITE_PERL}/XML/DTDParse
	${MKDIR} ${SITE_PERL}/modules
	${INSTALL_DATA} ${WRKSRC}/modules/*.pl ${SITE_PERL}/modules
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/dtd.dtd ${XMLDIR}
	${ECHO_CMD} \
		'PUBLIC "-//Norman Walsh//DTD DTDParse V2.0//EN" "dtd.dtd"' \
		>${XMLDIR}/catalog

post-install:
	${MKCATALOG} -c ${PREFIX}/share/xml/catalog -q install dtdparse
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/sample; \
		${INSTALL_DATA} sample* simple* ${EXAMPLESDIR}
# README is not 'additional' documentation because it's the only file
# that contains copyright notice
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README WhatsNew ${DOCSDIR}

.include <bsd.port.mk>

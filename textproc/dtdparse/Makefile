# New ports collection makefile for:   dtdparse
# Date created:                29 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtdparse
PORTVERSION=	2.0.b6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dtdparse
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse a DTD and produce an XML document that represents it

RUN_DEPENDS=	${SITE_PERL}/Text/DelimMatch.pm:${PORTSDIR}/textproc/p5-DelimMatch \
		${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM

USE_PERL5=	yes
NO_BUILD=	yes
XMLDIR=		${PREFIX}/share/xml/${PORTNAME}
SCRIPTS=	dtdflatten dtdformat dtdparse \
		tools/contentmodel tools/dtdstats tools/elements

post-patch:
	cd ${WRKSRC}; \
		${PERL} -pi -e 's,/usr/local/bin/perl5,${PERL},' ${SCRIPTS}
	${PERL} -pi -e 's,modules/,XML/DTDParse/,' ${WRKSRC}/dtdformat

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
	${MKDIR} ${SITE_PERL}/XML/DTDParse
	${INSTALL_DATA} ${WRKSRC}/XML/DTDParse/*.pm ${SITE_PERL}/XML/DTDParse
	${INSTALL_DATA} ${WRKSRC}/modules/*.pl ${SITE_PERL}/XML/DTDParse
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/dtd.dtd ${XMLDIR}
	${ECHO_CMD} \
		'PUBLIC "-//Norman Walsh//DTD DTDParse V2.0//EN" "dtd.dtd"' \
		>${XMLDIR}/catalog

post-install:
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/sample; \
		${INSTALL_DATA} sample* simple* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README WhatsNew ${DOCSDIR}

.include <bsd.port.mk>

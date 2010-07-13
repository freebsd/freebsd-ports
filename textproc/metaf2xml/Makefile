# New ports collection makefile for:	metaf2xml
# Date created:		2006-08-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	metaf2xml
PORTVERSION=	1.40
CATEGORIES=	textproc
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Parses METAR, TAF, and SYNOP messages and stores the components in XML

MAKE_ARGS=	CGI_BIN_DIR=${PREFIX}/www/metaf2xml/cgi-bin \
		HTDOCS_DIR=${PREFIX}/www/metaf2xml/htdocs \
		METAF2XML=${PREFIX} \
		METAF2XML_LIB=${PREFIX}/${SITE_PERL_REL} \
		METAF2XML_XSL=${DATADIR}
NO_BUILD=	yes
USE_PERL5_RUN=	yes

pre-install:
	${MKDIR} ${PREFIX}/www/metaf2xml/cgi-bin \
		${PREFIX}/www/metaf2xml/htdocs

do-install:
	cd ${WRKSRC}; ${MAKE} ${MAKE_ARGS} install-all

.include <bsd.port.mk>

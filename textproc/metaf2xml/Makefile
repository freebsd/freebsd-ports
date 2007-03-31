# New ports collection makefile for:	metaf2xml
# Date created:		2006-08-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	metaf2xml
PORTVERSION=	1.23
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Parses and decodes aviation routine and stores the components in XML

MAKE_ARGS=	CGI_BIN_DIR=${TARGETDIR}/www/metaf2xml/cgi-bin \
		HTDOCS_DIR=${TARGETDIR}/www/metaf2xml/htdocs \
		METAF2XML=${TARGETDIR} \
		METAF2XML_LIB=${TARGETDIR}/${SITE_PERL_REL} \
		METAF2XML_XSL=${DATADIR}
NO_BUILD=	yes
USE_PERL5_RUN=	yes

pre-install:
	${MKDIR} ${TARGETDIR}/www/metaf2xml/cgi-bin \
		${TARGETDIR}/www/metaf2xml/htdocs

do-install:
	cd ${WRKSRC}; ${MAKE} ${MAKE_ARGS} install-all

.include <bsd.port.mk>

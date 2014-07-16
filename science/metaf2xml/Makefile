# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	metaf2xml
PORTVERSION=	1.55
CATEGORIES=	science perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Parse and Decode METAR, TAF, SYNOP and BUOY and Store as XML

OPTIONS_DEFINE=	APACHE DOCS
OPTIONS_SUB=	yes
APACHE_DESC=	Install Apache config file for metaf2xml (depends on Apache)

MAKE_ARGS=	CGI_BIN_DIR=${PREFIX}/www/metaf2xml/cgi-bin \
		HTDOCS_DIR=${PREFIX}/www/metaf2xml/htdocs \
		METAF2XML=${PREFIX} \
		METAF2XML_LIB=${PREFIX}/${SITE_PERL_REL} \
		METAF2XML_DOC=${DOCSDIR} \
		METAF2XML_XSL=${DATADIR}
NO_BUILD=	yes
USES=		perl5 tar:tgz
USE_PERL5=	install run

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
MAKE_ARGS+=	CONF_DIR=${PREFIX}/${APACHEETCDIR}/Includes
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/metaf2xml/cgi-bin \
		${STAGEDIR}${PREFIX}/www/metaf2xml/htdocs

do-install:
	cd ${WRKSRC}; ${MAKE} ${MAKE_ARGS} install-all

.include <bsd.port.mk>

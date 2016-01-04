# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	metaf2xml
PORTVERSION=	1.58
CATEGORIES=	science perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse and Decode METAR, TAF, SYNOP, BUOY and AMDAR and Write as XML

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	APACHE DOCS
OPTIONS_SUB=	yes
APACHE_DESC=	Install Apache config file for metaf2xml (depends on Apache)

MAKE_ARGS=	CGI_BIN_DIR=${WWWDIR}/cgi-bin \
		HTDOCS_DIR=${WWWDIR}/htdocs \
		METAF2XML=${PREFIX} \
		METAF2XML_LIB=${PREFIX}/${SITE_PERL_REL} \
		METAF2XML_DOC=${DOCSDIR} \
		METAF2XML_XSL=${DATADIR} \
		BUILD_ROOT=${STAGEDIR}
NO_BUILD=	yes
USES=		perl5 shebangfix tar:tgz
USE_PERL5=	install run
SHEBANG_FILES=	metaf.pl metaf2xml.pl metafsrc2raw.pl

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
MAKE_ARGS+=	CONF_DIR=${PREFIX}/${APACHEETCDIR}/Includes
.endif

.include <bsd.port.mk>

# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	metaf2xml
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	science perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse and Decode METAR, TAF, SYNOP, BUOY and AMDAR and Write as XML

LICENSE=	GPLv2+

RUN_DEPENDS=	p5-CGI>0:www/p5-CGI

OPTIONS_DEFINE=	APACHE DOCS
OPTIONS_SUB=	yes
APACHE_DESC=	Install Apache config file for metaf2xml (depends on Apache)

MAKE_ARGS=	CGI_BIN_DIR=${WWWDIR}/cgi-bin \
		CGI_DATA_DIR=/var/tmp \
		CGI_LOG_DIR=/var/tmp \
		HTDOCS_DIR=${WWWDIR}/htdocs \
		METAF2XML=${PREFIX} \
		METAF2XML_LIB=${PREFIX}/${SITE_PERL_REL} \
		METAF2XML_DOC=${DOCSDIR} \
		METAF2XML_MAN=${PREFIX}/man \
		METAF2XML_XSL=${DATADIR} \
		BUILD_ROOT=${STAGEDIR} \
		PERL=${LOCALBASE}/bin/perl
NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix tar:tgz
USE_PERL5=	run
SHEBANG_FILES=	metaf.pl metaf2xml.pl metafsrc2raw.pl

PLIST_SUB=	VERSION=${PORTVERSION}

APACHE_MAKE_ARGS=	CONF_DIR=${PREFIX}/${APACHEETCDIR}/Includes
APACHE_USE=		APACHE_RUN=22+

post-patch:
	${REINPLACE_CMD} 's|%%METAF2XML_XSL%%|../../../${DATADIR_REL}| ; \
		s|%%METAF2XML_BIN%%|../../../bin|' \
		${WRKSRC}/install.pl

.include <bsd.port.mk>

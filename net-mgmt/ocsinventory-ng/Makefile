# New ports collection makefile for:   	ocsinventory-ng
# Date created:                         28 Sep 2007
# Whom:                                	araujo
#
# $FreeBSD$

PORTNAME=	ocsinventory-ng
PORTVERSION=	1.02.1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/ocsinventory/OCS%20Inventory%20NG/1.02
DISTNAME=	OCSNG_UNIX_SERVER-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Open Computer and Software Inventory Next Generation

RUN_DEPENDS=	${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql50 \
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite

USE_APACHE=	1.3+
USE_MYSQL=	yes
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	3
USE_PHP=	mysql pcre zlib session xml gd zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "Apache dtd ocsreports" ${DATADIR}/)
	@${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${DATADIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>

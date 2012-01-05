# New ports collection makefile for:   	ocsinventory-ng
# Date created:                         28 Sep 2007
# Whom:                                	araujo
#
# $FreeBSD$

PORTNAME=	ocsinventory-ng
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://launchpad.net/ocsinventory-server/stable-${PORTVERSION}/${PORTVERSION}/+download/
DISTNAME=	OCSNG_UNIX_SERVER-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Open Computer and Software Inventory Next Generation

RUN_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI \
		${SITE_PERL}/Net/IP.pm:${PORTSDIR}/net-mgmt/p5-Net-IP \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
		${SITE_PERL}/XML/Entities.pm:${PORTSDIR}/textproc/p5-XML-Entities

FETCH_ARGS=
LICENSE=	GPLv2
USE_APACHE=	20+
USE_MYSQL=	41+
USE_PERL5=	5.8.0+
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	3
USE_PHP=	mysql pcre zlib session xml gd zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "Apache binutils dtd etc ocsreports" ${DATADIR}/)
	@${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${DATADIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>

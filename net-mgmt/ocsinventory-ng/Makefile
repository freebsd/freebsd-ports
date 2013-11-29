# $FreeBSD$

PORTNAME=	ocsinventory-ng
PORTVERSION=	2.0.5
CATEGORIES=	net-mgmt
MASTER_SITES=	https://launchpadlibrarian.net/99500930/
DISTNAME=	OCSNG_UNIX_SERVER-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Computer and Software Inventory Next Generation

LICENSE=	GPLv2

RUN_DEPENDS=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Compress-Raw-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Raw-Zlib \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-Apache-DBI>=0:${PORTSDIR}/www/p5-Apache-DBI \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-XML-Entities>=0:${PORTSDIR}/textproc/p5-XML-Entities

USES=		perl5
USE_APACHE_RUN=	22+
USE_MYSQL=	41+
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=	5
USE_PHP=	mysql pcre zlib session xml gd zip openssl mbstring
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "Apache binutils dtd etc ocsreports" ${DATADIR}/)
	@${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${DATADIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>

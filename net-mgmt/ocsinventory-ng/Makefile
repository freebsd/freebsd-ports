# $FreeBSD$

PORTNAME=	ocsinventory-ng
PORTVERSION=	2.1.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://launchpadlibrarian.net/179739296/
DISTNAME=	OCSNG_UNIX_SERVER-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Computer and Software Inventory Next Generation

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

RUN_DEPENDS=	p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Compress-Raw-Zlib>=0:archivers/p5-Compress-Raw-Zlib \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-Apache-DBI>=0:www/p5-Apache-DBI \
		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
		p5-XML-Entities>=0:textproc/p5-XML-Entities

USES=		mysql perl5
USE_APACHE_RUN=	22+
WANT_PHP_WEB=	yes
USE_PHP=	mysql pcre zlib session xml gd zip openssl mbstring
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "Apache binutils dtd etc ocsreports" ${STAGEDIR}${DATADIR}/)
	@${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${STAGEDIR}${DATADIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

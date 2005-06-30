# New ports collection makefile for:	base
# Date created:		2004-11-29
# Whom:			Linh Pham <question+fbsdports@closedsrc.org>
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	secureideas

MAINTAINER=	question+fbsdports@closedsrc.org
COMMENT=	Basic Analysis and Security Engine - analyzing Snort alerts

RUN_DEPENDS=	${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort \
		${ADODB_DIR}/adodb.inc.php:${PORTSDIR}/databases/adodb \
		${LOCALBASE}/share/pear/Image/Graph.php:${PORTSDIR}/graphics/pear-Image_Graph

USE_PHP=	yes
USE_REINPLACE=	yes

ADODB_DIR=	${LOCALBASE}/share/adodb

SUB_FILES=	pkg-message
DOCS=		docs/CHANGELOG docs/CREDITS docs/README docs/TODO docs/UPGRADE

do-build:
	@${REINPLACE_CMD} -e 's,DBlib_path = "",DBlib_path = "${ADODB_DIR}",' \
		${WRKSRC}/base_conf.php.dist

do-install:
	${MKDIR} ${PREFIX}/www/base/includes/templates/default
	${INSTALL_DATA} ${WRKSRC}/*.php ${WRKSRC}/*.dist ${PREFIX}/www/base
.for dir in admin help includes languages setup
	${MKDIR} ${PREFIX}/www/base/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.php ${PREFIX}/www/base/${dir}
.endfor
.for dir in images sql styles
	${MKDIR} ${PREFIX}/www/base/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${PREFIX}/www/base/${dir}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

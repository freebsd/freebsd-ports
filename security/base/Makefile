# New ports collection makefile for:	base
# Date created:		2004-11-29
# Whom:			Linh Pham <question+fbsdports@closedsrc.org>
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	1.2.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	secureideas

MAINTAINER=	question+fbsdports@closedsrc.org
COMMENT=	Basic Analysis and Security Engine - analyzing Snort alerts

RUN_DEPENDS=	${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort \
		${ADODB_DIR}/adodb.inc.php:${PORTSDIR}/databases/adodb \
		${LOCALBASE}/share/pear/Image/Graph.php:${PORTSDIR}/graphics/pear-Image_Graph

USE_PHP=	gd gettext pcre session zlib

ADODB_DIR=	${LOCALBASE}/share/adodb

SUB_FILES=	pkg-message
DOCS=		docs/CHANGELOG docs/CREDITS docs/README docs/TODO docs/UPGRADE

OPTIONS=	MYSQL "Enable MySQL support" off \
		PGSQL "Enable PostgreSQL support" off \
		PDF "Enable PDF support" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
USE_PHP+=	mysql
.endif
.if defined(WITH_PGSQL)
USE_PGSQL=	yes
USE_PHP+=	pgsql
.endif
.if defined(WITH_PDF)
RUN_DEPENDS+=	${LOCALBASE}/share/fpdf/fpdf.php:${PORTSDIR}/print/fpdf
.endif

# we need this because we USE_PHP after bsd.port.pre.mk is included
.include "${PORTSDIR}/Mk/bsd.php.mk"

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

.include <bsd.port.post.mk>

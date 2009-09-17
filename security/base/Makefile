# New ports collection makefile for:	base
# Date created:		2004-11-29
# Whom:			Linh Pham <question+fbsdports@closedsrc.org>
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	1.4.4
CATEGORIES=	security
MASTER_SITES=	SF/secureideas/BASE/${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Basic Analysis and Security Engine - analyzing Snort alerts

RUN_DEPENDS=	${ADODB_DIR}/adodb.inc.php:${PORTSDIR}/databases/adodb \
		${LOCALBASE}/share/pear/Image/Graph.php:${PORTSDIR}/graphics/pear-Image_Graph \
		${LOCALBASE}/share/pear/Mail.php:${PORTSDIR}/mail/pear-Mail \
		${LOCALBASE}/share/pear/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime

#WRKSRC=		${WRKDIR}/${PORTNAME}-php4

USE_PHP=	gd gettext pcre session zlib ctype

ADODB_DIR=	${LOCALBASE}/share/adodb

SUB_FILES=	pkg-message
DOCS=		docs/CHANGELOG docs/CREDITS docs/README docs/README.mssql \
		docs/TODO docs/UPGRADE docs/GPL docs/base_faq.rtf

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

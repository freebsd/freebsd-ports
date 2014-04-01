# Created by: John Oxley <john@yoafrica.com>
# $FreeBSD$

PORTNAME=	vexim
DISTVERSION=	2.2.2_rc1
CATEGORIES=	mail www
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	feld
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Web interface for managing virtual domains for exim

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

VEXIMDIR=	www/${PORTNAME}
WRKSRC=		${WRKDIR}/vexim-release

SUB_FILES=	pkg-message
NO_BUILD=	yes
USE_PHP=	gettext session posix
USES=		gettext

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
USE_PHP+=	pgsql
.endif

post-patch:
	${RM} -r ${WRKSRC}/.hg ${WRKSRC}/.hgtags ${WRKSRC}/vexim/adminuserchange.phps
	${MV} ${WRKSRC}/vexim/config/variables.php ${WRKSRC}/vexim/config/variables.php.dist

do-install:
	@${ECHO} "Installing in ${VEXIMDIR}"
	${MKDIR} ${PREFIX}/${VEXIMDIR}
	cd ${WRKSRC}/vexim && ${FIND} . \
		-type d -exec ${MKDIR} ${PREFIX}/${VEXIMDIR}/{} \;  \
		-o -type f \
		-exec ${INSTALL_DATA} {} ${PREFIX}/${VEXIMDIR}/{} \;
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/setup && ${FIND} . \
		-type d -exec ${MKDIR} ${DATADIR}/{} \; \
		-o -type f \
		-exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} docs \
		-type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
		-o -type f \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.for i in INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

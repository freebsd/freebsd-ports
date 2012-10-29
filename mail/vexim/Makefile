# Created by: John Oxley <john@yoafrica.com>
# $FreeBSD$

PORTNAME=	vexim
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://silverwraith.com/vexim/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web interface for managing virtual domains for exim

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

VEXIMDIR=	www/${PORTNAME}
WRKSRC=		${WRKDIR}/vexim2

SUB_FILES=	pkg-message
NO_BUILD=	yes
USE_PHP=	gettext session posix

OPTIONS_DEFINE=	MYSQL PGSQL DOCS
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
WITH_PGSQL=	yes
USE_PHP+=	pgsql
.endif

post-patch:
	${FIND} ${WRKSRC} -name CVS -prune -exec ${RM} -r {} \;

do-install:
	@${ECHO} "Installing in ${VEXIMDIR}"
	${MKDIR} ${PREFIX}/${VEXIMDIR}
	cd ${WRKSRC}/vexim && ${FIND} . \! -path '*.svn*' \
		-type d -exec ${MKDIR} ${PREFIX}/${VEXIMDIR}/{} \;  \
		-o \! -path '*.svn*' -type f \
		-exec ${INSTALL_DATA} {} ${PREFIX}/${VEXIMDIR}/{} \;
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/setup && ${FIND} . \! -path '*.svn*' \
		-type d -exec ${MKDIR} ${DATADIR}/{} \; \
		-o \! -path '*.svn*' -type f \
		-exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} docs \! -path '*.svn*' \
		-type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
		-o \! -path '*.svn*' -type f \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.for i in INSTALL LICENSE README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

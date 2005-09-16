# New ports collection makefile for:    pam_mysql
# Date created:				29 August 2000
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	pam_mysql
PORTVERSION=	0.6.0
CATEGORIES=	security databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A pam module for authenticating with MySQL

USE_REINPLACE=	yes
USE_MYSQL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} --with-pam-mods-dir=${PREFIX}/lib --with-pam=/usr

PLIST_FILES=	lib/pam_mysql.la lib/pam_mysql.so

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${ECHO_MSG} "================================================================================"
	@${ECHO_MSG} "Copy/move/symlink ${PREFIX}/lib/pam_mysql.so to /usr/lib/pam_mysql.so"
	@${ECHO_MSG} "to be able to use it. Read files in ${PREFIX}/share/doc/pam_mysql"
	@${ECHO_MSG} "for info on how to set up."
	@${ECHO_MSG} "================================================================================"

.include <bsd.port.mk>

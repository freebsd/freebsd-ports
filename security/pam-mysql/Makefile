# New ports collection makefile for:    pam_mysql
# Date created:				29 August 2000
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	pam_mysql
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	security databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A pam module for authenticating with MySQL

USE_MYSQL=	yes
BROKEN_WITH_MYSQL=	41
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

pre-build:
	@cd ${WRKSRC} && ${GMAKE} clean

do-build:
	${CC} -O -pipe -fpic -DPIC -Wall -I${LOCALBASE}/include -c ${WRKSRC}/pam_mysql.c -o ${WRKSRC}/pam_mysql.o
	${LD} -x --shared -o ${WRKSRC}/pam_mysql.so ${WRKSRC}/pam_mysql.o -lpam -lcrypt -L${LOCALBASE}/lib/mysql -lmysqlclient

do-install:
	@${INSTALL_DATA} ${WRKSRC}/pam_mysql.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Changelog ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Readme ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} "================================================================================"
	@${ECHO_MSG} "Copy/move/symlink ${PREFIX}/lib/pam_mysql.so to /usr/lib/pam_mysql.so"
	@${ECHO_MSG} "to be able to use it. Read files in ${PREFIX}/share/doc/pam_mysql"
	@${ECHO_MSG} "for info on how to set up."
	@${ECHO_MSG} "================================================================================"

.include <bsd.port.post.mk>

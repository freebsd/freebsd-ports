# New ports collection makefile for:    pam_mysql
# Date created:				29 August 2000
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	pam_mysql
PORTVERSION=	0.5
CATEGORIES=	security databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A pam module for authenticating with MySQL

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	@cd ${WRKSRC} && ${GMAKE} clean

do-build:
	${CC} -O -pipe -fpic -DPIC -Wall -I${PREFIX}/include -c ${WRKSRC}/pam_mysql.c -o ${WRKSRC}/pam_mysql.o
	${LD} -x --shared -o ${WRKSRC}/pam_mysql.so ${WRKSRC}/pam_mysql.o -lpam -lcrypt -L${PREFIX}/lib/mysql -lmysqlclient

do-install:
	@${INSTALL_DATA} ${WRKSRC}/pam_mysql.so ${PREFIX}/lib
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/pam_mysql
	@${INSTALL_DATA} ${WRKSRC}/Changelog ${PREFIX}/share/doc/pam_mysql/
	@${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/pam_mysql/
	@${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/share/doc/pam_mysql/

post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "Copy/move/symlink ${PREFIX}/lib/pam_mysql.so to /usr/lib/pam_mysql.so"
	@${ECHO} "to be able to use it. Read files in ${PREFIX}/share/doc/pam_mysql"
	@${ECHO} "for info on how to set up."
	@${ECHO} "================================================================================"

.include <bsd.port.post.mk>

# Ports collection makefile for:  finger_mysql
# Date created:			  03 Mar 2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	finger_mysql
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.fsix.net/files/ \
		http://www.zone-h.org/files/49/ \
		http://downloads.securityfocus.com/vulnerabilities/exploits/
DISTNAME=	finger_mysql.c
EXTRACT_SUFX=	#none
EXTRACT_ONLY=	#none

MAINTAINER=	Yonatan@xpert.com
COMMENT=	Threaded MySQL scanner

LIB_DEPENDS=	mysqlclient:${PORTSDIR}/databases/mysql323-client/

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/finger_mysql

post-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/

do-build:
	${CC} ${CFLAGS} -L${PREFIX}/lib/mysql -I${PREFIX}/include ${PTHREAD_LIBS} -lmysqlclient -o ${WRKSRC}/finger_mysql ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/finger_mysql ${PREFIX}/bin

.include <bsd.port.mk>

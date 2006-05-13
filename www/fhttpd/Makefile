# New ports collection makefile for:	fhttpd
# Date created:		21 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	fhttpd
PORTVERSION=	0.4.2
CATEGORIES=	www
MASTER_SITES=	http://www.fhttpd.org/ \
		ftp://ftp.fhttpd.org/fhttpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++-based FTP/HTTP server that supports modules

LOGFILE=	share/fhttpd/fhttpd.log
PLIST_SUB+=	LOGFILE=${LOGFILE}

post-extract:
	@${CP} ${FILESDIR}/fhttpd.sh ${WRKSRC}

pre-patch:
	(cd ${WRKSRC} && ${TAR} xf http-root.tar)

pre-install:
	${RM} -rf ${WRKSRC}/http-root/pub/dummy_directory
	${REINPLACE_CMD} -e "s:%%LOGFILE%%:${PREFIX}/${LOGFILE}:g" \
		${WRKSRC}/fhttpd.sh ${WRKSRC}/http-root/root-fhttpd.conf
	${REINPLACE_CMD} -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/http-root/root-fhttpd.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fhttpd.sh ${PREFIX}/etc/rc.d
.for PROG in fhttpd fhttpd-file fhttpd-log
	${INSTALL_PROGRAM} ${WRKSRC}/${PROG} ${PREFIX}/sbin
.endfor
	${INSTALL_DATA} ${WRKSRC}/http-root/root-fhttpd.conf ${PREFIX}/etc/fhttpd.conf
	${MKDIR} ${PREFIX}/share/fhttpd/bin
	${INSTALL_SCRIPT} ${WRKSRC}/http-root/bin/* ${PREFIX}/share/fhttpd/bin
	${MKDIR} ${PREFIX}/share/fhttpd/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/http-root/cgi-bin/f* ${PREFIX}/share/fhttpd/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/http-root/cgi-bin/.index.html ${PREFIX}/share/fhttpd/cgi-bin
	${MKDIR} ${PREFIX}/share/fhttpd/incoming
.for DIR in icons private pub
	${MKDIR} ${PREFIX}/share/fhttpd/${DIR}
	${INSTALL_DATA} ${WRKSRC}/http-root/${DIR}/* ${PREFIX}/share/fhttpd/${DIR}/
.endfor
.for DIR in private pub
	${INSTALL_DATA} ${WRKSRC}/http-root/${DIR}/.[fhi]* ${PREFIX}/share/fhttpd/${DIR}/
.endfor
.for FILE in index.html noaccess.html
	${INSTALL_DATA} ${WRKSRC}/http-root/${FILE} ${PREFIX}/share/fhttpd/
.endfor

post-install:
	${TOUCH} ${PREFIX}/${LOGFILE}

.include <bsd.port.mk>

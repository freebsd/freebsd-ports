# New ports collection makefile for:	pserv
# Date created:				Wed Oct 15 14:16:14 CEST 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	pserv
PORTVERSION=	3.0.b2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-20-Oct-03
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	A portable and small webserver written in C

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g;s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/pserv.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pserv ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/mime_types.dat ${PREFIX}/etc/mime.types
	${INSTALL_DATA} ${WRKSRC}/pserv.conf ${PREFIX}/etc/
	${INSTALL_SCRIPT} ${FILESDIR}/pserv.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.mk>

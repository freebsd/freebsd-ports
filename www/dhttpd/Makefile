# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	dhttpd
PORTVERSION=	1.02a
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Minimal secure webserver. Fast and efficient, no cgi-bin support

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-1.02-4
BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	sbin/dhttpd man/man1/dhttpd.1.gz

USE_RC_SUBR=	dhttpd

pre-everything::
	@${ECHO_MSG} "=============================================================="
	@${ECHO_MSG} "To change the default document root"
	@${ECHO_MSG} "${PREFIX}/www/data edit"
	@${ECHO_MSG} "${FILESDIR}/patch-config.hh"
	@${ECHO_MSG} "for your needs and re-compile dhhtpd."
	@${ECHO_MSG} "=============================================================="

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/src/config.hh \
		${WRKSRC}/dhttpd.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>

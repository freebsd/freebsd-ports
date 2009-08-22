# New ports collection makefile for:	pserv
# Date created:				Wed Oct 15 14:16:14 CEST 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	pserv
PORTVERSION=	3.4
CATEGORIES=	www
MASTER_SITES=	SF
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A portable and small webserver written in C

GNU_CONFIGURE=	yes

OPTIONS=	LOG "Enable logging" on \
		PHP "Enable PHP support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PHP)
USE_PHP=	yes
WANT_PHP_CGI=	yes
.endif

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g;s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/defaults/pserv.conf ${WRKSRC}/sources/main.h
.if defined(WITHOUT_LOG)
	@${REINPLACE_CMD} "s|define LOG|undef LOG|" \
		${WRKSRC}/sources/main.h
.endif
.if defined(WITHOUT_PHP)
	@${REINPLACE_CMD} "s|define PHP|undef PHP|" \
		${WRKSRC}/sources/main.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sources/pserv ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/etc/pserv
	${INSTALL_DATA} ${WRKSRC}/defaults/mime_types.dat ${PREFIX}/etc/pserv/mime.types
	${INSTALL_DATA} ${WRKSRC}/defaults/pserv.conf ${PREFIX}/etc/pserv/pserv.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pserv.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>

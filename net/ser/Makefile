# New ports collection makefile for:	ser
# Date created:				6 November 2002
# Whom:					andrei
#
# $FreeBSD$
#

PORTNAME=	ser
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.berlios.de/pub/ser/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A very fast and configurable SIP proxy

LIB_DEPENDS=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient \
		xml2.5:${PORTSDIR}/textproc/libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	"LDFLAGS=-L${LOCALBASE}/lib"

MAN8=		ser.8
MAN5=		ser.cfg.5
MANCOMPRESSED=	no

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
MAKE_ENV+=	MYSQL=mysql
.endif

.if !defined(WITHOUT_POSTGRESQL)
USE_PGSQL=	yes
PLIST_SUB+=	POSTGRESQL=""
.else
PLIST_SUB+=	POSTGRESQL="@comment "
MAKE_ENV+=	POSTGRESQL=postgres
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile completely on sparc64 or ia64"
.endif

post-install:
	${SED} 's|%%LOCALBASE%%|${LOCALBASE}|g ; s|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/modules/acc/etc/radiusclient.conf > \
			${WRKDIR}/radiusclient.conf
	${INSTALL_DATA} ${WRKSRC}/modules/acc/etc/sip_dictionary \
		${PREFIX}/etc/ser
	${INSTALL_DATA} ${WRKSRC}/modules/acc/etc/servers \
		${PREFIX}/etc/ser/servers.sample
	${INSTALL_DATA} ${WRKDIR}/radiusclient.conf \
		${PREFIX}/etc/ser/radiusclient.conf.default
	if [ ! -e ${PREFIX}/etc/ser/radiusclient.conf ]; then \
		${INSTALL_DATA} ${WRKDIR}/radiusclient.conf \
			${PREFIX}/etc/ser/radiusclient.conf; \
	fi

.include <bsd.port.post.mk>

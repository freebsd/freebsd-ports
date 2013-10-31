# Created by: andrei
# $FreeBSD$

PORTNAME=	ser
PORTVERSION=	0.9.6
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/ser/ \
		http://download2.berlios.de/ser/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Fast and configurable SIP proxy

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
USE_RC_SUBR=	ser
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NOPRECIOUSMAKEVARS=	yes

MAN8=		ser.8
MAN5=		ser.cfg.5
MANCOMPRESSED=	no

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !defined(WITH_SYSTEM_MALLOC)
MAKE_ENV+=	"extra_defs=-DF_MALLOC -DPKG_MALLOC"
.endif

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

.if !defined(WITHOUT_PRESENCE)
PLIST_SUB+=	PA=""
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
.else
PLIST_SUB+=	PA="@comment "
MAKE_ENV+=	PA=pa
.endif

.if !defined(WITHOUT_RADIUS)
PLIST_SUB+=	RADIUS=""
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
.else
PLIST_SUB+=	RADIUS="@comment "
MAKE_ENV+=	RADIUS="auth_radius group_radius uri_radius avp_radius"
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile completely on ia64, powerpc, or sparc64
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

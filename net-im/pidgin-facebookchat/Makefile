# Created by: ports@c0decafe.net <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	pidgin-facebookchat
PORTVERSION=	1.69
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PROJECTHOST}-source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Facebook Chat for Pidgin

LICENSE=	GPLv3

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib
BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

DEPRECATED=	obsolete, development has ceased, not staged
EXPIRATION_DATE=	2014-07-27

PROJECTHOST=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/purple-2/libfacebook.so

NO_STAGE=	yes
do-patch:
	${REINPLACE_CMD} -e "s#i686-pc-freebsd6.0-gcc#${CC}#; \
	s#/usr/local/#${LOCALBASE}/#g; \
	s#/usr/include/json-glib-1.0#${LOCALBASE}/include/json-glib-1.0 \
	-L${LOCALBASE}/lib/#g" \
		${WRKSRC}/Makefile

do-build:
	${MAKE} -C ${WRKSRC} libfacebookbsd60.so

do-install:
	${MKDIR} ${PREFIX}/lib/purple-2/
	${INSTALL_DATA} ${WRKSRC}/libfacebook.so ${PREFIX}/lib/purple-2/

.include <bsd.port.mk>

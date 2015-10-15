# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ntopng
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/ntop/${PORTNAME}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Fails to build

LIB_DEPENDS=	librrd.so:${PORTSDIR}/databases/rrdtool \
		libluajit-5.1.so:${PORTSDIR}/lang/luajit \
		libndpi.so:${PORTSDIR}/net/ndpi \
		libzmq.so:${PORTSDIR}/net/libzmq4

GNU_CONFIGURE=	yes
USE_SQLITE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=	 	autoreconf cpe gmake libtool pathfix pkgconfig tar:tgz
SUB_FILES=	ntopng-geoipupdate.sh

CPE_VENDOR=	ntop

OPTIONS_DEFINE=	GEOIP NLS
OPTIONS_DEFAULT=	GEOIP
GEOIP_BUILD_DEPENDS=	geoiplookup:${PORTSDIR}/net/GeoIP
NLS_USES=	gettext

USE_RC_SUBR=	ntopng

post-extract:
	@${FIND} ${WRKSRC} -name "*~" -delete
	@${RMDIR} ${WRKSRC}/httpdocs/ssl
	@${RMDIR} ${WRKSRC}/httpdocs/geoip

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DATADIR}/httpdocs
	${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	cd ${WRKSRC}/httpdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/httpdocs
	cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/scripts

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ntopng-geoipupdate.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

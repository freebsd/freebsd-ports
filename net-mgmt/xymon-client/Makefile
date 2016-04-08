# $FreeBSD$

PORTNAME=	xymon
PORTVERSION=	4.3.27
PORTREVISION=	0
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/xymon/Xymon/${PORTVERSION}
PKGNAMESUFFIX=	-client${PKGNAMESUFFIX2}
DIST_SUBDIR=	repacked

MAINTAINER=	feld@FreeBSD.org
COMMENT=	System for monitoring servers and networks - Client

LICENSE=	GPLv2

USERS=	xymon
GROUPS=	xymon

# Options
XYMONUSER?=	xymon
XYMONHOSTIP?=	127.0.0.1

SUB_LIST+=	XYMONUSER="${XYMONUSER}"

MAKE_JOBS_UNSAFE=	yes
USES=		cpe gmake
CONFIGURE_ENV=	MAKE=${MAKE_CMD}
MAKE_ENV+=	XYMONUSER="${XYMONUSER}"
MAKE_ENV+=	XYMONHOSTIP="${XYMONHOSTIP}"
MAKE_ENV+=	INSTALLROOT="${STAGEDIR}"
MAKE_ENV+=	PKGBUILD=1
MANPREFIX=	${STAGEDIR}${PREFIX}
USE_RC_SUBR=	xymon-client
PLIST_SUB+=	XYMONUSER="${XYMONUSER}"
CONFIG_FILES=	clientlaunch.cfg xymonclient.cfg localclient.cfg

# Configure script is interactive
do-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

.include <bsd.port.mk>

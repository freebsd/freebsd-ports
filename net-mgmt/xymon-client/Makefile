# $FreeBSD$

PORTNAME=	xymon
PORTVERSION=	4.3.12
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

MAKE_JOBS_UNSAFE=	yes
USES=		gmake
CONFIGURE_ENV=	MAKE=gmake
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

post-install:
.for i in ${CONFIG_FILES}
	${CP} -np ${STAGEDIR}${WWWDIR}/client/etc/${i}.DIST \
		${STAGEDIR}${WWWDIR}/client/etc/${i} || ${TRUE}
.endfor

.include <bsd.port.mk>

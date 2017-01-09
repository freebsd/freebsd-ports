# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	istatserver
PORTVERSION=	3.01
CATEGORIES=	sysutils
MASTER_SITES=	https://s3.amazonaws.com/bjango/files/istatserverlinux/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Daemon for iStat iPhone application

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libsqlite3.so:databases/sqlite3

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

USERS=	istat
GROUPS=	istat

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/istatserver ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/istatserver
	${INSTALL_DATA} ${WRKSRC}/resource/istatserver.conf \
		${STAGEDIR}${PREFIX}/etc/istatserver/istatserver.conf.sample
	${INSTALL_DATA} ${WRKSRC}/resource/istatserver_generated.conf \
	${STAGEDIR}${PREFIX}/etc/istatserver/istatserver_generated.conf.sample
	${CHOWN} -R ${USERS} ${STAGEDIR}${PREFIX}/etc/istatserver
	${INSTALL_MAN} ${WRKSRC}/resource/istatserver.1 \
	 		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/resource/istatserver.conf.5 \
	 		${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>

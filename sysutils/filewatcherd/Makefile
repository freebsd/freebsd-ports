# Created by: Natacha Porte <natbsd@instinctive.eu>
# $FreeBSD$

PORTNAME=	filewatcherd
PORTVERSION=	1.0b3
CATEGORIES=	sysutils

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Daemon that watches files and runs commands when they change

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	faelys
GH_TAGNAME=	1.0-beta3

USE_RC_SUBR=	filewatcherd

SUB_FILES=	pkg-message
PLIST_FILES=	sbin/filewatcherd etc/watchtab.sample man/man8/filewatcherd.8.gz man/man5/watchtab.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/filewatcherd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/filewatcherd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/watchtab.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${FILESDIR}/watchtab.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>

# Created by: Natacha Porte <natbsd@instinctive.eu>
# $FreeBSD$

PORTNAME=	filewatcherd
PORTVERSION=	1.0b1
DISTNAME=	${PORTNAME}-${GH_TAGNAME}
CATEGORIES=	sysutils

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Daemon that watches files and runs commands when they change

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	faelys
GH_COMMIT=	a2b8081
GH_TAGNAME=	1.0-beta1

USE_RC_SUBR=	filewatcherd

SUB_FILES=	pkg-message
PLIST_FILES=	sbin/filewatcherd etc/watchtab.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/filewatcherd ${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/watchtab.sample ${PREFIX}/etc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

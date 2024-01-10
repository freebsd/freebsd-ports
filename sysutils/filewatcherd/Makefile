PORTNAME=	filewatcherd
DISTVERSION=	1.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Daemon that watches files and runs commands when they change
WWW=		https://github.com/faelys/filewatcherd/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	faelys

USE_RC_SUBR=	filewatcherd

SUB_FILES=	pkg-message
PLIST_FILES=	etc/watchtab.sample \
		share/man/man5/watchtab.5.gz \
		share/man/man8/filewatcherd.8.gz \
		sbin/filewatcherd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/filewatcherd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/filewatcherd.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/watchtab.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_DATA} ${FILESDIR}/watchtab.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>

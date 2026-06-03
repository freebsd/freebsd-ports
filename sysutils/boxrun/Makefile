PORTNAME=	boxrun
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	sysutils

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	Sandboxed command execution using FreeBSD jails
WWW=		https://gitlab.com/tgasiba/boxrun

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_ACCOUNT=	tgasiba
GL_PROJECT=	boxrun

PLIST_FILES=	sbin/boxrun \
		share/boxrun/pf.conf.sample \
		share/man/man1/boxrun.1.gz

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/boxrun ${WRKSRC}/boxrun.c -ljail

do-install:
	${INSTALL_PROGRAM} -m 4755 ${WRKSRC}/boxrun \
		${STAGEDIR}${PREFIX}/sbin/boxrun
	${INSTALL_MAN} ${WRKSRC}/boxrun.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/boxrun.1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/boxrun
	${INSTALL_DATA} ${WRKSRC}/pf.conf.sample \
		${STAGEDIR}${PREFIX}/share/boxrun/pf.conf.sample

.include <bsd.port.mk>

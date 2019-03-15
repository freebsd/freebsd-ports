# $FreeBSD$

PORTNAME=	nsysctl
DISTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	New sysctl utility with libxo and extra options

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_COMMIT=	102780d056c2f03d1653f7c3f0bd9d8d5d4e91fd

PLIST_FILES=	bin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>

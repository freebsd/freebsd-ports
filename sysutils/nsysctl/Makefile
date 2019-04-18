# $FreeBSD$

PORTNAME=	nsysctl
DISTVERSION=	0.2
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to get or set the kernel state supporting libxo output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo.so:devel/libsysctlmibinfo

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	ad19c188fd36e5d4950e4560274ade3a259d4099

PLIST_FILES=	sbin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	nsysctl
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to get or set the kernel state supporting libxo output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo.so:devel/libsysctlmibinfo

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	be430829dd2ba9a69aee02f25d56a196983d96b4

PLIST_FILES=	man/man8/${PORTNAME}.8.gz \
		sbin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>

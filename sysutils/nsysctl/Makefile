# $FreeBSD$

PORTNAME=	nsysctl
DISTVERSION=	0.9.1
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to get or set the kernel state supporting libxo output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo.so:devel/libsysctlmibinfo

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	a59ec8cfcd5cbb77fa06bc5787c6d718d2b3e501

PLIST_FILES=	man/man8/${PORTNAME}.8.gz \
		sbin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>

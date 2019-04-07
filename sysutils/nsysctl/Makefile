# $FreeBSD$

PORTNAME=	nsysctl
DISTVERSION=	0.1.1
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	New sysctl utility with libxo and extra options

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo.so:devel/libsysctlmibinfo

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	f71d2fded69b95808f9247f7e01866d7a92b7ff9

PLIST_FILES=	bin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>

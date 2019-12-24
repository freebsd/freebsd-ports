# Created by: rene
# $FreeBSD$

PORTNAME=	biosfont
PORTVERSION=	1.3
CATEGORIES=	sysutils

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Kernel module to retrieve bitmap fonts from BIOS memory

LICENSE=	BSD2CLAUSE

# only platforms guaranteed to be ok, feedback/patches are welcome
ONLY_FOR_ARCHS=	amd64 i386

USES=		uidfix kmod
USE_GITHUB=	yes
GH_ACCOUNT=	rene0
WRKSRC_SUBDIR=	biosfont

post-install:
	${INSTALL_DATA} ${WRKSRC}/biosfont.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/biosfont.4 ${STAGEDIR}${PREFIX}/man/man4

.include <bsd.port.mk>

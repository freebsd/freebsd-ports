PORTNAME=	biosfont
PORTVERSION=	1.3.1
CATEGORIES=	sysutils
FJ_ACCOUNT=	rene0

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Kernel module to retrieve bitmap fonts from BIOS memory

LICENSE=	BSD2CLAUSE

# only platforms guaranteed to be ok, feedback/patches are welcome
ONLY_FOR_ARCHS=	amd64 i386

USES=		kmod uidfix
USE_FORGEJO=	yes
WRKSRC_SUBDIR=	biosfont

post-install:
	${INSTALL_DATA} ${WRKSRC}/biosfont.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/biosfont.4 ${STAGEDIR}${PREFIX}/share/man/man4

.include <bsd.port.mk>

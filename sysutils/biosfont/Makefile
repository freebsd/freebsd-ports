PORTNAME=	biosfont
PORTVERSION=	1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/rene0/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Kernel module to retrieve bitmap fonts from BIOS memory
WWW=		https://codeberg.org/rene0/biosfont

LICENSE=	BSD2CLAUSE

# only platforms guaranteed to be ok, feedback/patches are welcome
ONLY_FOR_ARCHS=	amd64 i386

USES=		kmod uidfix
WRKSRC=		${WRKDIR}/${PORTNAME}
WRKSRC_SUBDIR=	biosfont

post-install:
	${INSTALL_DATA} ${WRKSRC}/biosfont.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/biosfont.4 ${STAGEDIR}${PREFIX}/share/man/man4

.include <bsd.port.mk>

PORTNAME=	kldpatch
PORTVERSION=	20090116
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/kldpatch/
DISTNAME=	${PORTVERSION}-${PORTNAME}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Utility to patch modules and kernel
WWW=		http://info.iet.unipi.it/~luigi/FreeBSD/

LICENSE=	BSD2CLAUSE

USES=		tar:tgz

PLIST_FILES=	share/man/man8/${PORTNAME}.8.gz sbin/kldpatch

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>

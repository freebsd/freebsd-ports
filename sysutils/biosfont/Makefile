# Created by: rene
# $FreeBSD$

PORTNAME=	biosfont
PORTVERSION=	1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://rene-ladan.nl/pub/distfiles/
MASTER_SITE_SUBDIR=rene

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Kernel module to retrieve bitmap fonts from BIOS memory

LICENSE=	BSD2CLAUSE

# only platforms guaranteed to be ok, feedback/patches are welcome
ONLY_FOR_ARCHS=	i386 amd64

USES=		uidfix kmod

.include <bsd.port.pre.mk>

PLIST_SUB+=	PREFIX=${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/biosfont.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/biosfont.4 ${STAGEDIR}${PREFIX}/man/man4

.include <bsd.port.post.mk>

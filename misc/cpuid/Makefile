# Created by: ijliao

PORTNAME=	cpuid
PORTVERSION=	3.3
PORTREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	http://www.ka9q.net/code/cpuid/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CPU identification utility

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd
PLIST_FILES=	bin/cpuid
ONLY_FOR_ARCHS=	i386 amd64

CONFLICTS_INSTALL=	gmap # bin/cpuid

.include <bsd.port.mk>

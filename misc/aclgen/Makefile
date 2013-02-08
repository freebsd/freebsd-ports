# Created by: igor@zynaps.ru
# $FreeBSD$

PORTNAME=	aclgen
PORTVERSION=	2.02
CATEGORIES=	misc
MASTER_SITES=	ftp://gatling.ikk.sztaki.hu/pub/aclgen/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimize Cisco routers IP access lists

NO_WRKSUBDIR=	yes

MAKEFILE=	/usr/share/mk/bsd.prog.mk
MAKE_ARGS=	PROG=aclgen

MAN1=		aclgen.1
PLIST_FILES=	bin/aclgen

post-patch:
	@${REINPLACE_CMD} -e \
		's|<malloc.h>|<unistd.h>| ; \
		 s|^void main|int main|' ${WRKSRC}/aclgen.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aclgen ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aclgen.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>

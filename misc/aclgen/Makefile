PORTNAME=	aclgen
PORTVERSION=	2.02
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://gatling.ikk.sztaki.hu/pub/aclgen/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimize Cisco routers IP access lists
WWW=		https://gatling.ikk.sztaki.hu/~kissg/pd/

NO_WRKSUBDIR=	yes

MAKEFILE=	/usr/share/mk/bsd.prog.mk
MAKE_ARGS=	PROG=aclgen

PLIST_FILES=	bin/aclgen \
		share/man/man1/aclgen.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|<malloc.h>|<unistd.h>| ; \
		 s|^void main|int main|' ${WRKSRC}/aclgen.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aclgen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aclgen.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

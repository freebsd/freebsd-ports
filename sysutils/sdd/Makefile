# $FreeBSD$

PORTNAME=	sdd
PORTVERSION=	1.52
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/sdd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Faster and improved version of dd

USES=		gmake
MAKE_ENV=	MAKEPROG="${GMAKE}" CCOM="${CC}" COPTX="${CFLAGS}"
PLIST_FILES=	bin/sdd man/man1/sdd.1.gz

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" || ${CC} != "cc"
post-extract:
	@${LN} -sf i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${ARCH}-freebsd-${CC}.rul
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdd/OBJ/${ARCH}-freebsd-${CC}/sdd \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sdd/sdd.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>

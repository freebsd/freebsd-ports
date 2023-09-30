PORTNAME=	zidrav
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}4unix/${PORTVERSION}
DISTNAME=	zidrav4unix-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	File corruption detection and repair program
WWW=		https://sourceforge.net/projects/zidrav/

LICENSE=	GPLv2

USE_CXXSTD=	gnu++98
CFLAGS=		-std=gnu++98
ALL_TARGET=	zidrav
PLIST_FILES=	bin/zidrav man/man1/zidrav.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/zidrav.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-Dcrc32_type=long
.else
CFLAGS+=	-Dcrc32_type=int
.endif

.if ! empty(ARCH:Mmips*) || ${ARCH} == powerpc || ${ARCH} == powerpc64
CFLAGS+=	-DCPU_BIGENDIAN
.endif

.include <bsd.port.mk>

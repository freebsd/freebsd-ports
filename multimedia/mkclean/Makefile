# $FreeBSD$

PORTNAME=	mkclean
PORTVERSION=	0.8.7
CATEGORIES=	multimedia
MASTER_SITES=	SF/matroska/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Clean and optimize Matroska and WebM files

LICENSE=	BSD

USE_BZIP2=	yes
HAS_CONFIGURE=	yes

USES=		iconv gmake

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -liconv

MAKE_ENV+=	"LFLAGS=${LDFLAGS}"
MAKEFILE=	GNUmakefile
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

PLIST_FILES=	bin/mkclean \
		bin/mkWDclean

post-extract:
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/corec/tools/coremake/gcc_mak.inc
	@${RM} ${WRKSRC}/libmatroska2/test/test.proj

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: gmake: GNUmakefile: No such file or directory
.endif

.include <bsd.port.post.mk>

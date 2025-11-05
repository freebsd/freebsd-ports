PORTNAME=	spar
PORTVERSION=	0.5.10
PORTREVISION=	7
CATEGORIES=	math devel
MASTER_SITES=	SF/${PORTNAME}/Spar/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modular math parser
WWW=		https://spar.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix libtool ncurses readline
DOS2UNIX_FILES=	lib/randist/rand.c
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

CPPFLAGS+=	-DWANT_OBSOLETE_TYPEDEFS
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion -Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,-ldl,,g" \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/lib/module/Makefile.in
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/spar/*.so

.include <bsd.port.post.mk>

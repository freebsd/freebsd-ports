PORTNAME=	spar
PORTVERSION=	0.5.10
PORTREVISION=	6
CATEGORIES=	math devel
MASTER_SITES=	SF/${PORTNAME}/Spar/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modular math parser
WWW=		http://spar.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix libtool ncurses readline
DOS2UNIX_FILES=	lib/randist/rand.c
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,-ldl,,g" \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/lib/module/Makefile.in
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/spar/*.so

.include <bsd.port.post.mk>

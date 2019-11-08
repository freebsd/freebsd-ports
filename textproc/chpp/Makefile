# Created by: Andrey Zakhvatov <andy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chpp
PORTVERSION=	0.3.5
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://www.complang.tuwien.ac.at/schani/chpp/files/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-intrusive full-featured text preprocessor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgc.so:devel/boehm-gc

USES=		autoreconf gmake makeinfo
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		chpp

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} != "aarch64" && ${ARCH} != "amd64" && ${ARCH} != "i386" && ${ARCH} != "powerpc64"
BROKEN=		Does not compile
.endif

post-extract:
.for i in getopt.h regex.h gc/gc.h
	@cd ${WRKSRC} && ${MV} -f ${i} ${i}.dist
.endfor

post-patch:
	@${REINPLACE_CMD} -e \
		's| getopt.c getopt.h getopt1.c | | ; \
		 s| regex.c regex.h | | ; \
		 /LDADD/s| gc/gc.a | -lgc -lgnuregex | ; \
		 s|^YFLAGS|AM_YFLAGS|' ${WRKSRC}/Makefile.am
.for i in arrayops.c builtins.c stringops.c
	@${REINPLACE_CMD} -e \
		's|"../regex.h"|<gnu/regex.h>|' ${WRKSRC}/builtins/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>

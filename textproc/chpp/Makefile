PORTNAME=	chpp
PORTVERSION=	0.3.5
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://www.complang.tuwien.ac.at/schani/chpp/files/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-intrusive full-featured text preprocessor
WWW=		https://www.complang.tuwien.ac.at/schani/chpp/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgc.so:devel/boehm-gc \
		libgnuregex.so.6:devel/libgnuregex

USES=		autoreconf gmake localbase:ldflags

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_USES=	makeinfo
DOCS_INFO=		chpp

.include <bsd.port.pre.mk>

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
.for i in arrayops.c stringops.c
	@${REINPLACE_CMD} -e \
		's|"../regex.h"|<gnu/regex.h>|' ${WRKSRC}/builtins/${i}
.endfor

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e \
		'/SUBDIRS/s|doc||' ${WRKSRC}/Makefile.am

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for filename in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${filename} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>

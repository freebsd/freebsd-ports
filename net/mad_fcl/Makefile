# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	mad_fcl
PORTVERSION=	1.7
CATEGORIES=	net
MASTER_SITES=	http://mad.cs.tut.fi/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File Delivery over Unidirectional Transport implementation

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libcurl.so:ftp/curl

USES=		dos2unix gmake ssl
MAKE_ENV=	LFLAGS="${LDFLAGS}"
MAKE_JOBS_UNSAFE= yes

CFLAGS+=	-DHAVE_SYS_TYPES_H -DHAVE_SYS_SELECT_H -DHAVE_UNISTD_H \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PORTDOCS=	README.TXT
PORTEXAMPLES=	fdt-example.xml flute-sdp-example.sdp
PLIST_FILES=	bin/flute bin/multis_flute

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e '/CC/s| =| ?=|; \
		 s|-O3 -g||; s|-D_ISOC99_SOURCE||; \
		 s|-D_XOPEN_SOURCE=500||; \
		 s|-I/usr/local/include/boost-1_33_1||; \
		 s|-L/usr/local/lib||; s|-lpthread|-lcompat|'
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|fopen64|fopen|; s|ftruncate64|ftruncate|; \
		 s|lseek64|lseek|; s|off64_t|off_t|; \
		 s|open64|open|; s|stat64|stat|'
	@${REINPLACE_CMD} -e \
		'/<curl\/types.h>/d' ${WRKSRC}/flutelib/http_file_repair.h
	@${REINPLACE_CMD} -e "s|/usr/local/ssl|${OPENSSLBASE}|" \
		${WRKSRC}/flute/Makefile \
		${WRKSRC}/multis_flute/Makefile \
		${WRKSRC}/repair_sender/Makefile \
		${WRKSRC}/UnitTest/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flute \
		${WRKSRC}/bin/multis_flute ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

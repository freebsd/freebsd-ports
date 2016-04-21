# Created by: alepulver
# $FreeBSD$

PORTNAME=	javaservicewrapper
PORTVERSION=	3.5.29
CATEGORIES=	sysutils java
MASTER_SITES=	http://wrapper.tanukisoftware.com/download/${PORTVERSION}/
DISTNAME=	wrapper_${PORTVERSION}_src

MAINTAINER=	mike.jakubik@gmail.com
COMMENT=	Application to solve problems common to many Java applications

ONLY_FOR_ARCHS=	i386 amd64

USE_JAVA=	1.4+
USE_ANT=	yes
USES=		gmake iconv

DATADIR=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if (${ARCH} == amd64)
MAKE_ARGS+=	-Dbits=64
.else
MAKE_ARGS+=	-Dbits=32
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS}| ; \
			s|/usr/local|${ICONV_PREFIX}|g ; \
			s|-liconv|${ICONV_LIB}|' \
		${WRKSRC}/src/c/Makefile-freebsd-x86-32.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${CP} -rp bin conf lib test ${STAGEDIR}${DATADIR}
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/wrapper
	${LN} -sf ${DATADIR}/bin/wrapper ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

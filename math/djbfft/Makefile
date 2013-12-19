# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	djbfft
PORTVERSION=	0.76
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://cr.yp.to/djbfft/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	An extremely fast library for floating-point convolution

LEGAL_TEXT=	No license -- see http://cr.yp.to/softwarelaw.html

DISABLE_SIZE=	yes
ALL_TARGET=
INSTALL_TARGET=setup check

HEADER_FILES=	complex4.h complex8.h fftc4.h fftc8.h fftfreq.h \
		fftr4.h fftr8.h real4.h real8.h
LIB_FILES=	libdjbfft.a

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -E -e 's!(djbfft.a)!lib\1!' {} \;
	@${REINPLACE_CMD} -E 's|("include)|\1/${PORTNAME}|' ${WRKSRC}/hier.c

do-configure:
	@${ECHO_CMD} '${CC} ${CFLAGS} -fPIC' > ${WRKSRC}/conf-cc
	@${ECHO_CMD} '${CC}' > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home
.ifdef(WITH_OPT_PENTIUM)
	@${ECHO_CMD} 'pentium' > ${WRKSRC}/conf-opt
.endif
.ifdef(WITH_OPT_PPRO)
	@${ECHO_CMD} 'ppro' > ${WRKSRC}/conf-opt
.endif
.ifdef(WITH_OPT_SPARC)
	@${ECHO_CMD} 'sparc' > ${WRKSRC}/conf-opt
.endif

pre-su-install:
	@${MKDIR} ${PREFIX}/include/${PORTNAME}

do-install:
.for file in ${HEADER_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/${PORTNAME}
.endfor
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib
.endfor

.include <bsd.port.pre.mk>

pre-everything::
.ifndef(WITH_OPT_PENTIUM)
	@${ECHO_MSG} '===> Set WITH_OPT_PENTIUM to optimize for both Pentium and Pentium MMX'
	@${ECHO_MSG} '     like processors.'
.endif
.ifndef(WITH_OPT_PPRO)
	@${ECHO_MSG} '===> Set WITH_OPT_PPRO to optimize for Pentium Pro, Pentium II, and'
	@${ECHO_MSG} '     Pentium III like processors.'
.endif
.ifndef(WITH_OPT_SPARC)
	@${ECHO_MSG} '===> Set WITH_OPT_SPARC to optimize for Sparc family of processors.'
	@${ECHO_MSG} '     Works well with UltraSPARC-I and UltraSPARC-II processors.'
.endif

.include <bsd.port.post.mk>

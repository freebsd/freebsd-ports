# New ports collection makefile for:	djbfft
# Date created:				Wed May 15 16:29:51 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	djbfft
PORTVERSION=	0.76
CATEGORIES=	math
MASTER_SITES=	http://cr.yp.to/djbfft/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	An extremely fast library for floating-point convolution

NO_PACKAGE=	Forbidden - we have patches to the distribution.

USE_SIZE=	yes
ALL_TARGET=
INSTALL_TARGET=setup check
USE_PERL5_BUILD=yes

post-patch:
	@${FIND} ${WRKSRC} -type f -exec \
		${PERL} -pi -e 's!(djbfft.a)!lib\1!' {} \;
	@${PERL} -pi -e 's|("include)|\1/${PORTNAME}|' ${WRKSRC}/hier.c

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

pre-install:
	@${MKDIR} ${PREFIX}/include/${PORTNAME}

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

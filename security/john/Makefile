# New ports collection makefile for:	John the Ripper
# Date created:				Sun Mar 09, 1997
# Whom:					David O'Brien <obrien@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	john
DISTVERSION=	1.7.8-jumbo-7
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/john/g/ \
		http://mirrors.kernel.org/openwall/projects/john/${DISTVERSION:C/-.*//}/ \
		http://distro.ibiblio.org/pub/linux/distributions/openwall/projects/john/${DISTVERSION:C/-.*//}/ \
		http://gd.tuwien.ac.at/opsys/linux/openwall/projects/john/${DISTVERSION:C/-.*//}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Featureful Unix password cracker

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

OSNAME=		${OPSYS:L}
CFLAGS+=	-DJOHN_SYSTEMWIDE=1 \
		-DJOHN_SYSTEMWIDE_HOME=\\"${DATADIR}\\" \
		-DCFG_FULL_NAME=\\"${PREFIX}/etc/${PORTNAME}.conf\\"

PORTDOCS=	CHANGES CONFIG EXAMPLES EXTERNAL FAQ MODES OPTIONS README \
		RULES CONTACT CREDITS

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
. if ${MACHINE_CPU:Msse2}
ALL_TARGET=	${OSNAME}-x86-sse2
. elif ${MACHINE_CPU:Mmmx}
ALL_TARGET=	${OSNAME}-x86-mmx
. else
ALL_TARGET=	${OSNAME}-x86-any
. endif
.elif ${ARCH} == "amd64"
ALL_TARGET=	${OSNAME}-x86-64
.elif ${ARCH} == "alpha"
ALL_TARGET=	${OSNAME}-alpha
.else
ALL_TARGET=	generic
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= gcc|= ${CC}|g' \
		-e 's|CFLAGS =.*|CFLAGS = -c ${CFLAGS}|g' \
			${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin|${LOCALBASE}/bin|' \
		${WRKSRC}/run/*.rb
	@${REINPLACE_CMD} -e '/_XOPEN_SOURCE/d' ${WRKSRC}/src/recovery.c

pre-build:
	@${ECHO_CMD}
	@${ECHO_CMD} "Building for ${ALL_TARGET}"
	@${ECHO_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run/john ${PREFIX}/bin
	${LN} -sf john ${PREFIX}/bin/xtract
	${LN} -sf john ${PREFIX}/bin/unshadow
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/run && ${INSTALL_DATA} *.??? [^j]*.conf ${DATADIR}
	cd ${WRKSRC}/run && ${INSTALL_SCRIPT} *.?? mailer ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/run/john.conf \
		${PREFIX}/etc/john.conf.default
.if !exists(${PREFIX}/etc/john.conf)
	${INSTALL_DATA} ${WRKSRC}/run/john.conf ${PREFIX}/etc
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

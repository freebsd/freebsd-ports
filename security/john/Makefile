# Ports collection makefile for:	John the Ripper
# Date created:				Sun Mar 09, 1997
# Whom:					David O'Brien <obrien@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	john
PORTVERSION=	1.7.2
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/john/f/ \
		ftp://ftp.ru.openwall.com/pub/projects/john/${PORTVERSION}/ \
		ftp://ftp.se.openwall.com/pub/projects/john/${PORTVERSION}/ \
		http://distro.ibiblio.org/pub/linux/distributions/openwall/projects/john/${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Featureful Unix password cracker

DATAFILES=	all.chr alnum.chr alpha.chr digits.chr lanman.chr password.lst
PORTDOCS=	CHANGES CONFIG EXAMPLES EXTERNAL FAQ MODES OPTIONS README \
		RULES CONTACT CREDITS

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_BZIP2=	yes

OSNAME=		${OPSYS:L}
CFLAGS+=	-DJOHN_SYSTEMWIDE=1 \
		-DJOHN_SYSTEMWIDE_HOME=\\"${DATADIR}\\" \
		-DCFG_FULL_NAME=\\"${PREFIX}/etc/${PORTNAME}.conf\\"

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

post-patch:
	@${REINPLACE_CMD} -e 's|= gcc|= ${CC}|g' \
		-e 's|CFLAGS =.*|CFLAGS = -c ${CFLAGS}|g' \
		${WRKSRC}/Makefile

pre-build:
	@${ECHO}
	@${ECHO} "Building for ${ALL_TARGET}"
	@${ECHO}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/run/john ${PREFIX}/bin
.for l in xtract unshadow
	${LN} -sf ${PREFIX}/bin/john ${PREFIX}/bin/${l}
.endfor
	@${MKDIR} ${DATADIR}
.for f in ${DATAFILES}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/run/${f} ${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/run/john.conf \
		${PREFIX}/etc/john.conf.default
.if !exists(${PREFIX}/etc/john.conf)
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/run/john.conf \
		${PREFIX}/etc/john.conf
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

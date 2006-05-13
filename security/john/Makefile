# Ports collection makefile for:  john
# Date created:			  Sun Mar 09, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	john
PORTVERSION=	1.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/john/f/ \
		ftp://ftp.ru.openwall.com/pub/projects/john/${PORTVERSION}/

MAINTAINER=	rainer.alves@gmail.com
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

# workaround for OSVERSION/ARCH detection before bsd.port.pre.mk
# (required for OPTIONS usage)
ARCH!=		/usr/bin/uname -p
OSVERSION!=	/sbin/sysctl -n kern.osreldate

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
. if ${OSVERSION} > 500000
# dumps core with sse2 + gcc 2.95
OPTIONS=	SSE2 "Enable SSE2 optimizations" off
. endif
.endif
.if ${ARCH} == "i386"
OPTIONS+=	MMX "Enable MMX optimizations" off
.endif

.include <bsd.port.pre.mk>

ALL_TARGET=	generic

.if defined(WITH_MMX)
. if defined(WITH_SSE2)
ALL_TARGET=	${OSNAME}-x86-sse2
. else
ALL_TARGET=	${OSNAME}-x86-mmx
. endif
.elif defined(WITH_SSE2)
ALL_TARGET=	${OSNAME}-x86-sse2
.elif ${ARCH} == "alpha"
ALL_TARGET=	${OSNAME}-alpha
.else
ALL_TARGET=	${OSNAME}-x86-any
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= gcc|= ${CC}|g' \
		-e 's|CFLAGS =.*|CFLAGS = -c ${CFLAGS}|g' \
		${WRKSRC}/Makefile

pre-build:
	@${ECHO} "Building for ${ALL_TARGET}"

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

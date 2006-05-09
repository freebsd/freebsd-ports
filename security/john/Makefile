# Ports collection makefile for:  john
# Date created:			  Sun Mar 09, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	john
PORTVERSION=	1.7.0.2
PORTREVISION=	1
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

.include <bsd.port.pre.mk>

OSNAME=		${OPSYS:L}
CFLAGS+=	-DJOHN_SYSTEMWIDE=1 \
		-DJOHN_SYSTEMWIDE_HOME=\\"${DATADIR}\\" \
		-DCFG_FULL_NAME=\\"${PREFIX}/etc/${PORTNAME}.conf\\"

ALL_TARGET=	generic
.if ${ARCH} == "i386"
. if defined(WITHOUT_MMX)
ALL_TARGET=	${OSNAME}-x86-any
. else
ALL_TARGET=	${OSNAME}-x86-mmx
. endif
.elif ${ARCH} == "alpha"
ALL_TARGET=	${OSNAME}-alpha
.endif

pre-everything::
.if !defined(WITHOUT_MMX) && ${ARCH} == "i386"
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable MMX optimizations by defining WITHOUT_MMX"
	@${ECHO_MSG}
.endif

post-patch:
	${REINPLACE_CMD} -e 's|= gcc|= ${CC}|g' \
		-e 's|CFLAGS =.*|CFLAGS = -c ${CFLAGS}|g' \
		${WRKSRC}/Makefile

pre-build:
	@${ECHO} "Building for ${ALL_TARGET}"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/run/john ${PREFIX}/bin
.for l in xtract unshadow
	${LN} -sf ${PREFIX}/bin/john ${PREFIX}/bin/${l}
.endfor
	${MKDIR} ${DATADIR}
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
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

# ex:ts=8
# Ports collection makefile for:  john
# Date created:			  Sun Mar 09, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	john
PORTVERSION=	1.6.34
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/john/dl/ \
		ftp://ftp.ru.openwall.com/pub/projects/john/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-1.6.tar.gz

MAINTAINER=	dom@helenmarks.co.uk
COMMENT=	Featureful Unix password cracker

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

OSNAME=		${OPSYS:S/F/f/:S/N/n/:S/O/o/:S/B/b/:S/S/s/:S/D/d/}

ALL_TARGET=	generic
.if ${MACHINE_ARCH} == "i386"
. if ${MACHINE_CPU:Mmmx}
ALL_TARGET=	${OSNAME}-x86-mmx-elf
. else
ALL_TARGET=	${OSNAME}-x86-any-elf
. endif
.elif ${MACHINE_ARCH} == "alpha"
ALL_TARGET=	${OSNAME}-alpha
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src
OLDSRC=		${WRKDIR}/${PORTNAME}-1.6/run

pre-build:
	@${ECHO} "Building for ${ALL_TARGET}"

do-configure:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKDIR}/${DISTNAME}/src/params.h \
		${WRKDIR}/${DISTNAME}/run/john.conf

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/run/john ${PREFIX}/bin
	@cd ${PREFIX}/bin ; ${LN} -sf john xtract
	@cd ${PREFIX}/bin ; ${LN} -sf john unshadow
	@${INSTALL_DATA} \
		${OLDSRC}/all.chr \
		${OLDSRC}/alpha.chr \
		${OLDSRC}/digits.chr \
		${OLDSRC}/lanman.chr \
		${WRKDIR}/${DISTNAME}/run/password.lst \
		${WRKDIR}/${DISTNAME}/run/john.conf \
			${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

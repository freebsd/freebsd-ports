# ex:ts=8
# Ports collection makefile for:  john
# Date created:			  Sun Mar 09, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	john
PORTVERSION=	1.6
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ca.openwall.com/pub/projects/john/ \
		http://www.openwall.com/john/ \
		ftp://ftp.ru.openwall.com/pub/projects/john/ \
		ftp://ftp.false.com/pub/security/projects/ \
		http://www.false.com/security/john/

USE_REINPLACE=	yes
MAINTAINER=	d.marks@student.umist.ac.uk

.include <bsd.port.pre.mk>

OSNAME=		${OPSYS:S/F/f/:S/N/n/:S/O/o/:S/B/b/:S/S/s/:S/D/d/}

.if ${MACHINE_ARCH} == "i386"
ARCHNAME=	x86
. if ${MACHINE_CPU:Mk6}
ALL_TARGET=	${OSNAME}-${ARCHNAME}-k6-elf
. elif ${MACHINE_CPU:Mmmx}
ALL_TARGET=	${OSNAME}-${ARCHNAME}-mmx-elf
. else
ALL_TARGET=	${OSNAME}-${ARCHNAME}-any-elf
. endif
.elif ${MACHINE_ARCH} == "alpha"
ARCHNAME=	alpha
ALL_TARGET=	${OSNAME}-${ARCHNAME}-any-elf
.else
ALL_TARGET=	generic
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src

pre-fetch:
	@${ECHO} "Building for ${ALL_TARGET}"

do-configure:
	@${REINPLACE_CMD} \
		-e 's,~/all.chr,${PREFIX}/share/john/all.chr,' \
		-e 's,~/alpha.chr,${PREFIX}/share/john/alpha.chr,' \
		-e 's,~/digits.chr,${PREFIX}/share/john/digits.chr,' \
		-e 's,~/lanman.chr,${PREFIX}/share/john/lanman.chr,' \
	${WRKDIR}/${DISTNAME}/run/john.ini

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/run/john ${PREFIX}/bin
	@cd ${PREFIX}/bin ; ${LN} -sf john xtract
	@cd ${PREFIX}/bin ; ${LN} -sf john unshadow
	@${INSTALL_DATA} \
		${WRKDIR}/${DISTNAME}/run/all.chr \
		${WRKDIR}/${DISTNAME}/run/alpha.chr \
		${WRKDIR}/${DISTNAME}/run/digits.chr \
		${WRKDIR}/${DISTNAME}/run/lanman.chr \
		${WRKDIR}/${DISTNAME}/run/password.lst \
		${WRKDIR}/${DISTNAME}/run/john.ini \
		${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

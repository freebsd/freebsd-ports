# ex:ts=8
# Ports collection makefile for:  ufcjohn
# Version required:     	  1.4
# Date created:			  Sun Mar 09, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.6 1998/07/28 01:56:02 obrien Exp $
#

DISTNAME=	john-1.6
CATEGORIES=	security
MASTER_SITES=	http://www.false.com/security/john/ \
		ftp://ftp.false.com/pub/security/john/

MAINTAINER=     obrien@FreeBSD.org

RESTRICTED=	"contains crypto (crypt())"

.include <bsd.port.pre.mk>

OSNAME=		${OPSYS:S/F/f/:S/N/n/:S/O/o/:S/B/b/:S/S/s/:S/D/d/}

.if (${ARCH} == "i386")
ARCHNAME=	x86
.else
ARCHNAME=	${ARCH}
.endif

#	could do something w/
#	if sysctl -n hw.model | grep AMD >/dev/null ; then echo AMD ; fi
.if defined(HAVE_K6)
ALL_TARGET=	${OSNAME}-${ARCHNAME}-k6-BINFMT
.elif defined(HAVE_MMX)
ALL_TARGET=	${OSNAME}-${ARCHNAME}-mmx-BINFMT
.else
ALL_TARGET=	${OSNAME}-${ARCHNAME}-any-BINFMT
.endif

.if ${PORTOBJFORMAT} == "elf"
ALL_TARGET:=	${ALL_TARGET:S/BINFMT$/${PORTOBJFORMAT}/}
.else
ALL_TARGET:=	${ALL_TARGET:S/BINFMT$/a.out/}
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src

pre-fetch:
	@${ECHO} "Building for ${ALL_TARGET}"

do-configure:
	@${MV} ${WRKDIR}/${DISTNAME}/run/john.ini ${WRKDIR}/${DISTNAME}/run/john.ini.in
	@${SED} -e "s:~/all.chr:${PREFIX}/share/john/all.chr:" \
	    -e "s:~/alpha.chr:${PREFIX}/share/john/alpha.chr:" \
	    -e "s:~/digits.chr:${PREFIX}/share/john/digits.chr:" \
	    ${WRKDIR}/${DISTNAME}/run/john.ini.in > ${WRKDIR}/${DISTNAME}/run/john.ini

do-install:
	@${MKDIR} ${PREFIX}/share/john
	@${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/run/john ${PREFIX}/bin
	@(cd ${PREFIX}/bin ; /bin/ln -sf john xtract)
	@(cd ${PREFIX}/bin ; /bin/ln -sf john unshadow)
	@${INSTALL_DATA} \
		${WRKDIR}/${DISTNAME}/run/all.chr \
		${WRKDIR}/${DISTNAME}/run/alpha.chr \
		${WRKDIR}/${DISTNAME}/run/digits.chr \
		${WRKDIR}/${DISTNAME}/run/password.lst \
		${WRKDIR}/${DISTNAME}/run/john.ini \
		${PREFIX}/share/john
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/john
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/john
.endif

.include <bsd.port.post.mk>

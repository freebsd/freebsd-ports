# ex:ts=8
# Ports collection makefile for:  ufcjohn
# Version required:     	  1.4
# Date created:			  Sun Mar 09, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.4 1997/11/26 01:40:34 obrien Exp $
#

DISTNAME=	john-1.5
CATEGORIES=	security
MASTER_SITES=	http://www.false.com/security/john/ \
		ftp://ftp.false.com/pub/security/john/

MAINTAINER=     obrien@FreeBSD.org

RESTRICTED=	"contains crypto (crypt())"

WRKSRC=		${WRKDIR}/${DISTNAME}/src
.if defined(HAVE_K6)
ALL_TARGET=	${OSNAME}-${ARCHNAME}-k6
.else
ALL_TARGET=	${OSNAME}-${ARCHNAME}-any
.endif

do-configure:
	${MV} ${WRKDIR}/${DISTNAME}/run/john.ini ${WRKDIR}/${DISTNAME}/run/john.ini.in
	${SED} -e "s:~/all.chr:${PREFIX}/share/john/all.chr:" \
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

.include <bsd.port.mk>

OSNAME!=	/usr/bin/uname -s | ${TR} [A-Z] [a-z]
.if (${ARCH} == "i386")
ARCHNAME=	x86
.else
ARCHNAME=	${ARCH}
.endif

# New ports collection makefile for:  pcal
# Date created:               10 June 2001
# Whom:                       mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	pcal
PORTVERSION=	4.7
CATEGORIES=	print
MASTER_SITES=	http://www.geocities.com/SunsetStrip/Palms/5555/PS/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}_tar_Z
EXTRACT_SUFX=	.txt

MAINTAINER=	mwest@uct.ac.za

WRKSRC=		${WRKDIR}/pcal.${PORTVERSION}
PAPERSIZE?=	A4
WWWSERVER!=	hostname

MAN1=		pcal.1

.include <bsd.port.pre.mk>

MAKE_ENV+=	PAPERSIZE="${PAPERSIZE}"
MAKE_ENV+=	CC="${CC}" HOST_CC="${CC}"

ALL_TARGET=	pcal

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR}; \
	  uudecode -p ${DISTDIR}/${DISTFILES} | ${TAR} xzf -; \
	)

pre-install:
	${MV} ${WRKSRC}/pcal.cgi ${WRKSRC}/pcal.cgi.tmp
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' \
		< ${WRKSRC}/pcal.cgi.tmp > ${WRKSRC}/pcal.cgi
	${MV} ${WRKSRC}/pcal.html ${WRKSRC}/pcal.html.tmp
	${SED} -e 's|@@WWWSERVER@@|${WWWSERVER}|' \
		< ${WRKSRC}/pcal.html.tmp > ${WRKSRC}/pcal.html
	${MV} ${WRKSRC}/pcalw.html ${WRKSRC}/pcalw.html.tmp
	${SED} -e 's|@@WWWSERVER@@|${WWWSERVER}|' \
		< ${WRKSRC}/pcalw.html.tmp > ${WRKSRC}/pcalw.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcal ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pcal.cgi ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/pcal.man ${PREFIX}/man/man1/pcal.1
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pcal.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pcalw.html ${DOCSDIR}

.include <bsd.port.post.mk>

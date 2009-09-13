# New ports collection makefile for:	nsc2ke
# Date created:        16 December 2003
# Whom:                thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	nsc2ke
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	math science
MASTER_SITES=	http://www-c.inria.fr/gamma/cdrom/ftp/nsc2ke/
DISTNAME=	${PORTNAME}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} nsc2ke.ps.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Navier-Stokes solver

RESTRICTED=	No resale, contact author for commercial usage

USE_FORTRAN=	yes
FFLAGS+=	-O2

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	NSC2KE

EXEMPLES=	DATA MESH gnu.data
TESTDIR?=	/tmp/testnsc2ke

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/NSC2KE ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/READ_ME ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/nsc2ke.ps.gz ${DOCSDIR}
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
.for fich in ${EXEMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${fich} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.if defined(MAINTAINER_MODE)
test:	install
	${MKDIR} ${TESTDIR}
.for fich in ${EXEMPLES}
	${INSTALL_DATA} ${WRKSRC}/${fich} ${TESTDIR}
.endfor
	(cd ${TESTDIR};	\
	NSC2KE;		\
	gnuplot < gnu.data)
.endif

.include <bsd.port.mk>

# New ports collection makefile for: w3 on Emacs
# Version required:	2.2.26	
# Date created:		31 December 1996
# Whom:			MITA Yoshio <mita@ee.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.5 1997/07/13 18:49:30 max Exp $
#

DISTNAME=	w3-2.2.26
CATEGORIES?=	www
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/network/WWW/w3/ \
		ftp://ftp.cs.indiana.edu/pub/elisp/w3/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS?=	emacs-19.34:${PORTSDIR}/editors/emacs
RUN_DEPENDS?=	emacs-19.34:${PORTSDIR}/editors/emacs

WRKSRC=		${WRKDIR}/w3
MAKE_ENV+=	EMACSCMD=${EMACSCMD} ELISPDIR=${ELISPDIR} \
		MKDIR="${MKDIR}" CP=${CP} \
		INFODIR=${INFODIR} \
		INSTALL_DATA="${INSTALL_DATA}"

VERSION=	2.2.26
EMACSCMD?=	emacs-19.34
PORTSDOCDIR=	${PREFIX}/share/doc/w3
SAMPLEDIR=	${PREFIX}/share/examples/w3
ELISPDIR?=	${PREFIX}/share/emacs/site-lisp
INFODIR=	${PREFIX}/info
ADDIR=		${X11BASE}/lib/X11/app-defaults
DIRSECTION=	The Emacs editor and associated tools
INFOFILE=	w3.info

post-build:
.for f in DEINSTALL INSTALL dot.emacs user-install
	@${SED} -e "s,%VERSION%,${VERSION},g" \
 		-e "s,%PREFIX%,${PREFIX},g" \
 		-e "s,%INFODIR%,${INFODIR},g" \
 		-e "s,%ELISPDIR%,${ELISPDIR},g" \
		-e "s,%INFOFILE%,${INFOFILE},g" \
 		-e "s,%ADDIR%,${ADDIR},g" \
		-e "s,%TOUCH%,${TOUCH},g" \
		-e "s,%MKDIR%,${MKDIR},g" \
		-e "s,%SAMPLEDIR%,${SAMPLEDIR},g" \
		-e "s,%DIRSECTION%,${DIRSECTION},g" \
		< ${FILESDIR}/${f}.tmpl > ${FILESDIR}/${f}
.endfor
	@${CP} ${FILESDIR}/DEINSTALL ${FILESDIR}/INSTALL ${PKGDIR}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTSDOCDIR}
	@${MKDIR} ${SAMPLEDIR}
.for f in dot.emacs dot.mosaic-hotlist-default 
	@${INSTALL_DATA} ${FILESDIR}/${f} ${SAMPLEDIR}
.endfor
	@${INSTALL_SCRIPT} ${FILESDIR}/user-install ${SAMPLEDIR}
.for f in W3.ad clean-cache Makefile w3.txi
	@${INSTALL_DATA} ${WRKSRC}/${f}  ${PORTSDOCDIR}
.endfor
.endif
	@${SETENV} MKDIR="${MKDIR}" TOUCH=${TOUCH} \
		INFODIR=${INFODIR} INFOFILE=${INFOFILE} \
		ELISPDIR=${ELISPDIR} ADDIR=${ADDIR} \
		DIRSECTION="${DIRSECTION}" \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL  

pre-clean:
	@${RM} -f ${FILESDIR}/DEINSTALL ${FILESDIR}/INSTALL \
		${FILESDIR}/dot.emacs ${FILESDIR}/user-install \
		${PKGDIR}/DEINSTALL ${PKGDIR}/INSTALL 

.include <bsd.port.mk>

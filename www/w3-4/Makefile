# New ports collection makefile for: w3 on Emacs
# Date created:		31 December 1996
# Whom:			MITA Yoshio <mita@ee.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	w3
PORTVERSION=	4.0.p46
CATEGORIES+=	www elisp
MASTER_SITES=	${MASTER_SITE_XEMACS}
MASTER_SITE_SUBDIR=	emacs-w3
DISTNAME=	w3-4.0pre.46

MAINTAINER=	kiri@FreeBSD.org

BUILD_DEPENDS?=	emacs-20.7:${PORTSDIR}/editors/emacs20
RUN_DEPENDS?=	emacs-20.7:${PORTSDIR}/editors/emacs20

GNU_CONFIGURE=	yes

MAKE_ENV+=	EMACSCMD=${EMACSCMD} ELISPDIR=${ELISPDIR} \
		MKDIR="${MKDIR}" CP=${CP} \
		INFODIR=${INFODIR} \
		INSTALL_DATA="${INSTALL_DATA}"

PORTSDOCDIR=	${PREFIX}/share/doc/w3
SAMPLEDIR=	${PREFIX}/share/examples/w3

post-build:
.for f in dot.emacs user-install
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
		< ${FILESDIR}/${f}.tmpl > ${WRKDIR}/${f}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTSDOCDIR}
	@${MKDIR} ${SAMPLEDIR}
.for f in dot.mosaic-hotlist-default
	@${INSTALL_DATA} ${FILESDIR}/${f} ${SAMPLEDIR}
.endfor
.for f in dot.emacs
	@${INSTALL_DATA} ${WRKDIR}/${f} ${SAMPLEDIR}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/user-install ${SAMPLEDIR}

.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

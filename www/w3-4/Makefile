# New ports collection makefile for: w3 on Emacs
# Version required:	2.2.26	
# Date created:		31 December 1996
# Whom:			MITA Yoshio <mita@ee.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1997/01/04 00:36:48 max Exp $
#

DISTNAME=	w3-2.2.26
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/elisp/w3/ \
		ftp://ftp.iij.ad.jp/pub/network/WWW/w3/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs

WRKSRC=		${WRKDIR}/w3

DOCDIR=		${PREFIX}/share/doc/w3
SAMPLEDIR=	${PREFIX}/share/examples/w3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${MKDIR} ${SAMPLEDIR}
.for f in dot.emacs dot.mosaic-hotlist-default 
	@${INSTALL_DATA} ${FILESDIR}/${f} ${SAMPLEDIR}
.endfor
	@${INSTALL_SCRIPT} ${FILESDIR}/user-install ${SAMPLEDIR}
.for f in W3.ad clean-cache Makefile w3.txi
	@${INSTALL_DATA} ${WRKSRC}/${f}  ${DOCDIR}
.endfor
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} /bin/sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

# New ports collection makefile for: w3 on Emacs
# Version required:	2.2.26	
# Date created:		30 November 1996
# Whom:			MITA Yoshio <mita@ee.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	w3-2.2.26
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/network/WWW/w3/ \
		ftp://ftp.cs.indiana.edu/pub/elisp/w3/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs

WRKSRC=		${WRKDIR}/w3

DOCDIR=		${PREFIX}/share/doc/w3

post-install:
.if !defined(NOPORTDOCS)
	@if [ ! -d ${DOCDIR} ]; then mkdir -p ${DOCDIR}; fi
.for f in .emacs .mosaic-hotlist-default 
	@${CP} ${FILESDIR}/${f} ${DOCDIR}
.endfor
	@${INSTALL_SCRIPT} ${FILESDIR}/user-install ${DOCDIR}
.for f in W3.ad clean-cache Makefile w3.txi
	@${CP} ${WRKSRC}/${f}  ${DOCDIR}
.endfor
.endif
	@/bin/sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

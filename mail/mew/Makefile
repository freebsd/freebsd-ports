# New ports collection makefile for: Mew
# Version required:	1.54
# Date created:		30 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.2 1997/01/03 16:48:34 max Exp $
#

DISTNAME=	mew-1.54
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/elisp/Mew/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs \
		mhmail:${PORTSDIR}/mail/mh

RESTRICTED=	"USA ITAR export restrictions (has PGP hooks)"

DOCDIR=		${PREFIX}/share/doc/mew
SAMPLEDIR=	${PREFIX}/share/examples/mew

post-install:
	@strip ${PREFIX}/bin/mewencode
.for f in mewencode mew-refile uumerge vscan
	@chown bin:bin ${PREFIX}/bin/${f}
	@chmod 555 ${PREFIX}/bin/${f}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/info/mew.info* ${PREFIX}/info
	@${INSTALL_SCRIPT} ${FILESDIR}/MH-postproc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/info/*.texi ${DOCDIR}
	@${MKDIR} ${SAMPLEDIR}
.for f in dot.emacs aliases dot.mh_profile scan.form
	@${INSTALL_DATA}  ${FILESDIR}/${f} ${SAMPLEDIR}
.endfor
	@${INSTALL_SCRIPT} ${FILESDIR}/user-install ${SAMPLEDIR}
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} /bin/sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

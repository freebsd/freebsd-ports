# New ports collection makefile for: Mew
# Version required:	1.54
# Date created:		14 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id$
#

DISTNAME=	mew-1.54
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/elisp/Mew/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs \
		mhmail:${PORTSDIR}/mail/mh \
		perl:${PORTSDIR}/lang/perl5

DOCDIR=		${PREFIX}/share/doc/mew

post-install:
	@strip ${PREFIX}/bin/mewencode
.for f in mewencode mew-refile uumerge vscan
	@chown bin:bin ${PREFIX}/bin/${f}
	@chmod 555 ${PREFIX}/bin/${f}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/info/mew.info* ${PREFIX}/info
	@${INSTALL_SCRIPT} ${FILESDIR}/MH-postproc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@if [ ! -d ${DOCDIR} ]; then mkdir -p ${DOCDIR}; fi
	@${CP} ${WRKSRC}/info/*.texi ${DOCDIR}
.for f in .emacs aliases .mh_profile scan.form
	${CP}  ${FILESDIR}/${f} ${DOCDIR}
.endfor
	@${INSTALL_SCRIPT} ${FILESDIR}/user-install ${DOCDIR}
.endif
	@/bin/sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

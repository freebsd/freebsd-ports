# New ports collection makefile for:	auctex
# Date created:				21 November 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=		auctex
PORTVERSION=		9.9p
CATEGORIES=		print elisp
MASTER_SITES=		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/auctex

MAINTAINER=		mkamm@gmx.net

# EMACS_NAME must be 'emacs' or 'xemacs' - it is used for byte compiling
#    emacs lisp files (*.el => *.elc)
# EMACS_PORT is only used for dependency registration, the installed bits
#    are always the same (regardless of what [x]emacs version is used)
.if !defined(EMACS_NAME)
.if exists(${LOCALBASE}/bin/xemacs)
EMACS_NAME = xemacs
EMACS_PORT = xemacs21
.else
EMACS_NAME = emacs
EMACS_PORT = emacs20
.endif
.endif
MAKE_ENV += EMACS='${EMACS_NAME}'

BUILD_DEPENDS =	${EMACS_NAME}:${PORTSDIR}/editors/${EMACS_PORT}
RUN_DEPENDS =	${EMACS_NAME}:${PORTSDIR}/editors/${EMACS_PORT} \
		latex:${PORTSDIR}/print/teTeX

.include <bsd.port.pre.mk>

.if ${PREFIX} != /usr/local
# adjust a hardcoded '/usr/local' string
post-patch:
	@${ECHO_MSG} "===>  Substituting hardcoded '/usr/local' paths"
	${PERL} -wpi -e 's¦/usr/local¦${PREFIX}¦g' ${WRKSRC}/tex.el
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/auctex
.for file in CHANGES INSTALLATION README
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/auctex
.endfor
	cd ${WRKSRC} &&  ${SETENV} ${MAKE_ENV} ${MAKE} install-info >/dev/null
	install-info --entry='* AUC-Tex mode: (auctex).	Emacs mode for editing TeX and LaTeX files.' --section='TeX' ${PREFIX}/info/auctex ${PREFIX}/info/dir
.endif
	@${CAT} ${PKGMESSAGE} | ${SED} 's¦/usr/local¦${PREFIX}¦g'

.include <bsd.port.post.mk>

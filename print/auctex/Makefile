# New ports collection makefile for:	auctex
# Date created:				21 November 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=		auctex
PORTVERSION=		10.0g
CATEGORIES=		print elisp
MASTER_SITES=		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/auctex

MAINTAINER=		mkamm@gmx.net

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

EMACS_PORT_NAME?=	emacs21
EMACS_NO_RUN_DEPENDS=	yes
LISPDIR=	${EMACS_SITE_LISPDIR}
MAKE_ARGS+=	lispdir=${PREFIX}/${LISPDIR}
PLIST_SUB+=	LISPDIR=${LISPDIR}

# adjust a hardcoded '/usr/local' string
post-patch:
	@${ECHO_MSG} "===>  Substituting hardcoded '/usr/local' paths"
	${PERL} -wpi -e 's?/usr/local?${PREFIX}?g' ${WRKSRC}/tex.el

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/auctex
.for file in CHANGES INSTALLATION README
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/auctex
.endfor
	cd ${WRKSRC} &&  ${SETENV} ${MAKE_ENV} ${MAKE} install-info >/dev/null
	install-info --entry='* AUC-Tex mode: (auctex).	Emacs mode for editing TeX and LaTeX files.' --section='TeX' ${PREFIX}/info/auctex ${PREFIX}/info/dir
.endif
	@${CAT} ${PKGMESSAGE} | ${SED} 's?/usr/local?${PREFIX}?g'

.include <bsd.port.mk>

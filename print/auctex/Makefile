# New ports collection makefile for:	auctex
# Date created:				21 November 1999
# Whom:					Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=		auctex
PORTVERSION=		11.13
CATEGORIES=		print elisp
MASTER_SITES=		http://savannah.nongnu.org/download/auctex/stable.pkg/${PORTVERSION}/

MAINTAINER=		yoichi@FreeBSD.org

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

EMACS_PORT_NAME?=	emacs21
EMACS_NO_RUN_DEPENDS=	yes
LISPDIR=	${EMACS_SITE_LISPDIR}
ALL_TARGET=	all contrib
INSTALL_TARGET=	install install-contrib
MAKE_ARGS+=	lispdir=${PREFIX}/${LISPDIR}
PLIST_SUB+=	LISPDIR=${LISPDIR}
USE_REINPLACE=	yes

# adjust a hardcoded '/usr/local' string
post-patch:
	@${ECHO_MSG} "===>  Substituting hardcoded '/usr/local' paths"
	${REINPLACE_CMD} -e 's?/usr/local?${PREFIX}?g' ${WRKSRC}/tex.el

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

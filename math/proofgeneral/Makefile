# New ports collection makefile for:   proofgeneral
# Date created:        11 August 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	proofgeneral
PORTVERSION=	3.5
CATEGORIES=	math elisp
MASTER_SITES=	http://proofgeneral.inf.ed.ac.uk/releases/ \
		http://www.cl.cam.ac.uk/Research/HVG/Isabelle/dist/contrib/ \
		http://isabelle.in.tum.de/dist/contrib/ \
		http://mirror.cse.unsw.edu.au/pub/isabelle/contrib/
DISTNAME=	ProofGeneral-3.5

MAINTAINER=	timbob@bigpond.com
COMMENT=	A generic interface for proof assistants

PKGNAMESUFFIX+=	-${EMACS_NAME}

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	${LOCALBASE}/share/applications/.keep_me:${PORTSDIR}/misc/kdehier

.include <bsd.port.pre.mk>

#
# Unless EMACS_PORT_NAME is overriden by the user,
# use any installed version of [X]Emacs.
#
# If there is none installed, use xemacs21-mule.
#
.if !defined(EMACS_PORT_NAME)
.if !exists(${LOCALBASE}/bin/emacs)
EMACS_PORT_NAME=xemacs21-mule

# xemacs21-mule does not depend on xemacs-packages, so add a dependency here
BUILD_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/lisp/xlib/xlib-xlib.el:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/lisp/xlib/xlib-xlib.el:${PORTSDIR}/editors/xemacs-packages
.else
EMACS_PORT_NAME=emacs21
.endif
.endif

# Needed for proper build- and run-time [x]xemacs dependencies,
# and the definition of EMACS_NAME and EMACS_SITE_LISPDIR
.include "${PORTSDIR}/Mk/bsd.emacs.mk"

MAKE_ARGS+=	EMACS_NAME=${EMACS_NAME} EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}
USE_GMAKE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

SUB_FILES=	pkg-message
SUB_LIST=	EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

MAN1=		proofgeneral.1
MANCOMPRESSED=	no
INFO=		PG-adapting ProofGeneral

.if !defined(NOPORTDOCS)
PORTDOCS=	PG-adapting_*.html ProofGeneral_*.html \
		ProofGeneral.pdf PG-adapting.pdf
MAKE_ARGS+=	INSTALL_DOC=doc.pdf
BUILD_DEPENDS+=	${LOCALBASE}/bin/texi2pdf:${PORTSDIR}/print/teTeX-base
.endif

post-patch:
	@${TOUCH} -m -r ${WRKSRC}/generic/proof-menu.el.orig \
	${WRKSRC}/generic/proof-menu.el
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/etc/desktop/proofgeneral.desktop

pre-build:
.if defined(BYTE_COMPILE)
	@${ECHO_CMD} "************************************************************"
	@${ECHO_CMD} "* Byte compilation may not work properly for all files...  *"
	@${ECHO_CMD} "************************************************************"
	@${RM} ${WRKSRC}/.byte-compile
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

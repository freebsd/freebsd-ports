# New ports collection makefile for:   proofgeneral
# Date created:        11 August 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	proofgeneral
PORTVERSION=	3.7.1
PORTREVISION=	1
CATEGORIES=	math elisp
MASTER_SITES=	http://proofgeneral.inf.ed.ac.uk/releases/
DISTNAME=	ProofGeneral-3.7.1
EXTRACT_SUFX=	.tgz

MAINTAINER=	timbob@bigpond.com
COMMENT=	A generic interface for proof assistants

PKGNAMESUFFIX+=	-${EMACS_NAME}

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

#
# Unless EMACS_PORT_NAME is overriden by the user,
# use any installed version of [X]Emacs.
#
# If there is none installed, use xemacs21-mule.
#
.if !defined(EMACS_PORT_NAME)
.if !exists(${LOCALBASE}/bin/emacs)
EMACS_PORT_NAME=xemacs21-mule
BUILD_DEPENDS+=	${LOCALBASE}/bin/xemacs:${PORTSDIR}/editors/${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/bin/xemacs:${PORTSDIR}/editors/${EMACS_PORT_NAME}

# xemacs21-mule does not depend on xemacs-packages, so add a dependency here
BUILD_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/lisp/xlib/xlib-xlib.el:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/lisp/xlib/xlib-xlib.el:${PORTSDIR}/editors/xemacs-packages
.else
EMACS_PORT_NAME=emacs
BUILD_DEPENDS+=	${LOCALBASE}/bin/emacs:${PORTSDIR}/editors/${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/bin/emacs:${PORTSDIR}/editors/${EMACS_PORT_NAME}
.endif
.endif

USE_EMACS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier
INSTALLS_ICONS=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

MAKE_ARGS+=	EMACS_NAME=${EMACS_NAME} EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

SUB_FILES=	pkg-message
SUB_LIST=	EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

MAN1=		proofgeneral.1
MANCOMPRESSED=	no
INFO=		PG-adapting ProofGeneral

.if !defined(NOPORTDOCS)
MAKE_ARGS+=	DOCSDIR=${DOCSDIR} INSTALLDOC=install-doc
BUILD_DEPENDS+=	${LOCALBASE}/bin/texi2pdf:${PORTSDIR}/print/teTeX-base
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/etc/desktop/proofgeneral.desktop
	@${TOUCH} ${WRKSRC}/.byte-compile
	@${REINPLACE_CMD} -e 's,%%EMACS_NAME%%,${EMACS_NAME},' \
		${WRKSRC}/isar/interface

pre-build:
#.if defined(BYTE_COMPILE)
	@${RM} ${WRKSRC}/.byte-compile || ${TRUE}
#.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/applications

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

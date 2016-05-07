# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	proofgeneral
PORTVERSION=	4.1
PORTREVISION=	10
CATEGORIES=	math elisp
MASTER_SITES=	http://proofgeneral.inf.ed.ac.uk/releases/
PKGNAMESUFFIX=	-${EMACS_NAME}
DISTNAME=	ProofGeneral-${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Generic interface for proof assistants

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USE_EMACS=	yes
INSTALLS_ICONS=	yes
USES=		gmake perl5 shebangfix tar:tgz
SHEBANG_FILES=	lego/legotags coq/coqtags isar/isartags
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${EMACS_NAME} == xemacs
IGNORE=	the ProofGeneral developers no longer support XEmacs
.endif

MAKE_ARGS+=	PREFIX="${LOCALBASE}" DEST_PREFIX="${STAGEDIR}${PREFIX}" \
	MAKE="${MAKE_CMD}" EMACS="${EMACS_NAME}" EMACS_NAME="${EMACS_NAME}" \
	DOCDIR="${STAGEDIR}${DOCSDIR}" MANDIR="${STAGEDIR}${PREFIX}/man/man1" \
	INFODIR="${STAGEDIR}${PREFIX}/info" \
	BINDIR="${STAGEDIR}${PREFIX}/bin" DESKTOP="${STAGEDIR}${PREFIX}/share" \
	EMACS_SITE_LISPDIR="${EMACS_SITE_LISPDIR}" \
	ELISPP="${EMACS_SITE_LISPDIR}/ProofGeneral" \
	ELISP="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/ProofGeneral" \
	ELISP_START="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/site-start.d" \
	DEST_ELISP="${PREFIX}/${EMACS_SITE_LISPDIR}/ProofGeneral"

SUB_FILES=	pkg-message
SUB_LIST=	EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

INFO=		PG-adapting ProofGeneral

.if ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=	DOCSDIR=${DOCSDIR} INSTALLDOC=install-doc
BUILD_DEPENDS+=	texi2html:textproc/texi2html
.endif

PORTDOCS=	AUTHORS BUGS CHANGES COMPATIBILITY COPYING INSTALL \
		PG-adapting ProofGeneral README REGISTER acl2 hol98 isar lego \
		pgshell phox twelf

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/etc/desktop/proofgeneral.desktop
	@${REINPLACE_CMD} -e  \
		"s|PERL_SCRIPTS = lego/legotags coq/coqtags isar/isartags||g" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e  "s|PG_SCRIPTS = bin/proofgeneral||g" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e  \
		's|PGHOMEDEFAULT=$$HOME|PGHOMEDEFAULT=${PREFIX}/${EMACS_SITE_LISPDIR}|g' \
	${WRKSRC}/bin/proofgeneral
	@${TOUCH} ${WRKSRC}/.byte-compile
	@${REINPLACE_CMD} -e 's,%%EMACS_NAME%%,${EMACS_NAME},' \
		${WRKSRC}/isar/interface

pre-build:
#.if defined(BYTE_COMPILE)
	@${RM} ${WRKSRC}/.byte-compile || ${TRUE}
#.endif

post-install:
	@${FIND} ${STAGEDIR}${DOCSDIR} -type d -empty -delete

.include <bsd.port.post.mk>

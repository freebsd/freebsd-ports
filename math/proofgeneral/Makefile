# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	proofgeneral
PORTVERSION=	4.1
PORTREVISION=	15
CATEGORIES=	math elisp
MASTER_SITES=	http://proofgeneral.inf.ed.ac.uk/releases/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	ProofGeneral-${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Generic interface for proof assistants

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		emacs gmake gnome perl5 shebangfix tar:tgz
EMACS_FLAVORS_EXCLUDE=	nox devel_nox

INSTALLS_ICONS=	yes
SHEBANG_FILES=	lego/legotags coq/coqtags isar/isartags
NO_ARCH=	yes

MAKE_ARGS+=	PREFIX="${LOCALBASE}" DEST_PREFIX="${STAGEDIR}${PREFIX}" \
	MAKE="${MAKE_CMD}" EMACS=emacs EMACS_NAME=emacs \
	DOCDIR="${STAGEDIR}${DOCSDIR}" MANDIR="${STAGEDIR}${PREFIX}/man/man1" \
	INFODIR="${STAGEDIR}${PREFIX}/${INFO_PATH}" \
	BINDIR="${STAGEDIR}${PREFIX}/bin" DESKTOP="${STAGEDIR}${PREFIX}/share" \
	EMACS_SITE_LISPDIR="${EMACS_SITE_LISPDIR}" \
	ELISPP="${EMACS_SITE_LISPDIR}/ProofGeneral" \
	ELISP="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/ProofGeneral" \
	ELISP_START="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/site-start.d" \
	DEST_ELISP="${PREFIX}/${EMACS_SITE_LISPDIR}/ProofGeneral"

SUB_FILES=	pkg-message
SUB_LIST=	EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

INFO=		PG-adapting ProofGeneral
PORTDOCS=	AUTHORS BUGS CHANGES COMPATIBILITY COPYING INSTALL \
		PG-adapting ProofGeneral README REGISTER acl2 hol98 isar lego \
		pgshell phox twelf

OPTIONS_DEFINE=	DOCS

DOCS_MAKE_ARGS=	DOCSDIR=${DOCSDIR} INSTALLDOC=install-doc
DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html

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
	@${REINPLACE_CMD} -e 's,%%EMACS_NAME%%,emacs,' \
		${WRKSRC}/isar/interface

pre-build:
#.if defined(BYTE_COMPILE)
	@${RM} ${WRKSRC}/.byte-compile || ${TRUE}
#.endif

post-install-DOCS-on:
	@${FIND} ${STAGEDIR}${DOCSDIR} -type d -empty -delete

post-install-DOCS-off:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

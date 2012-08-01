# New ports collection makefile for:   proofgeneral
# Date created:        11 August 2005
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	proofgeneral
PORTVERSION=	4.1
PORTREVISION=	3
CATEGORIES=	math elisp
MASTER_SITES=	http://proofgeneral.inf.ed.ac.uk/releases/
PKGNAMESUFFIX=	-${EMACS_NAME}
DISTNAME=	ProofGeneral-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	A generic interface for proof assistants

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_EMACS=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.ifdef (PACKAGE_BUILDING)
PLIST_SUB+=	PACKAGE_BUILDING="@comment "
.else
PLIST_SUB+=	PACKAGE_BUILDING=""
.endif

.if ${EMACS_NAME} == xemacs
IGNORE=	the ProofGeneral developers no longer support XEmacs
.endif

MAKE_ARGS+=	PREFIX="${LOCALBASE}" DEST_PREFIX="${PREFIX}" MAKE="${GMAKE}" \
	DOCDIR="${DOCSDIR}" MANDIR="${PREFIX}/man/man1" INFODIR="${PREFIX}/info" \
	BINDIR="${PREFIX}/bin" DESKTOP="${PREFIX}/share" \
	ELISPP="${EMACS_SITE_LISPDIR}/ProofGeneral" \
	ELISP="${PREFIX}/${EMACS_SITE_LISPDIR}/ProofGeneral" \
	ELISP_START="${PREFIX}/${EMACS_SITE_LISPDIR}/site-start.d" \
	EMACS="${EMACS_NAME}" EMACS_NAME="${EMACS_NAME}" \
	DEST_ELISP="${PREFIX}/${EMACS_SITE_LISPDIR}/ProofGeneral" \
	EMACS_SITE_LISPDIR="${EMACS_SITE_LISPDIR}"

SUB_FILES=	pkg-message
SUB_LIST=	EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}

MAN1=		proofgeneral.1
MANCOMPRESSED=	no
INFO=		PG-adapting ProofGeneral

.if !defined(NOPORTDOCS)
MAKE_ARGS+=	DOCSDIR=${DOCSDIR} INSTALLDOC=install-doc
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.endif

PORTDOCS=	AUTHORS BUGS CHANGES COMPATIBILITY COPYING INSTALL \
		PG-adapting ProofGeneral README REGISTER acl2 hol98 isar lclam lego \
		pgshell phox plastic twelf

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

# New ports collection makefile for:	lilypond-devel
# Date created:				2001-02-10
# Whom:					patrick
# based on print/lilypond originally by trevor
#
# $FreeBSD$
# $Id: Makefile,v 1.38 2004/01/12 18:00:21 patrick Exp $
#

PORTNAME=	lilypond
PORTVERSION=	2.1.8
PORTREVISION=	1
CATEGORIES=	print audio
MASTER_SITES=	http://lilypond.org/download/v2.1/ \
		http://www.atabersk.de/lilypond/
PKGNAMESUFFIX=	-devel

MAINTAINER=	atamaniuk-ports@frobs.net
COMMENT=	The GNU music typesetter (unstable/development)

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		mftrace:${PORTSDIR}/print/mftrace
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

MAN1=	abc2ly.1 as2text.1 convert-ly.1 etf2ly.1 lilypond.1 lilypond-bin.1 \
	lilypond-book.1 midi2ly.1 mup2ly.1 musedata2ly.1 pmx2ly.1
INFO=		lilypond lilypond-internals music-glossary

CONFLICTS=	lilypond-2.*

#INSTALLS_SHLIB not needed for phyton library midi.so

GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	YES
USE_PYTHON=	YES
MAKEFILE=	GNUmakefile
PKGINSTALL=	${WRKDIR}/pkg-install

CONFIGURE_ARGS+=	--with-kpathsea-include=${LOCALBASE}/include \
			--with-kpathsea-lib=${LOCALBASE}/lib
CONFIGURE_ENV+=		"CPPFLAGS=${CPPFLAGS}"

# inform kpathsea.h of getopt-prototype version
CFLAGS+=	-D__GNU_LIBRARY__
CPPFLAGS+=	-I${WRKSRC}/lily/out
CFLAGS+=	${CPPFLAGS}

.include <bsd.port.pre.mk>
MAKE_ENV+=	MAKE_PFA_FILES=1
ALL_TARGET=	all

.if ${OSVERSION} < 500000
USE_GCC=	3.3
.endif

SCRIPTS_ENV+=	PORTVERSION=${PORTVERSION}

.if defined(NOPORTDOCS)
PLIST_SUB+=	CONDITIONAL="@comment "
EXTRA_PATCHES+=	${FILESDIR}/extra-patch:GNUmakefile.in
.else
PLIST_SUB+=	CONDITIONAL=""
.endif
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

#IGNORING portlint 2.5.0 WARN: possible direct use of command "install" found at line 64. use ${INSTALL_foobaa} instead.
INSTALL_INFO?=	install-info

pre-configure:
	${SED} -e "s=%%LOCALBASE%%=${LOCALBASE}=g;s=%%DATADIRVERSION%%=${DATADIR}/${PORTVERSION}=g" \
		< ${FILESDIR}/pkg-install.in \
		| ${SED} -e "s=${PREFIX}=\$${PKG_PREFIX}=g" \
	> ${PKGINSTALL}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}/scripts
	cd ${WRKSRC}/input ; \
	${TAR} -chf - --exclude=out --exclude=CVS --exclude=GNUmakefile . | \
		${TAR} -xf - -C ${EXAMPLESDIR};
.for ii in login profile
	${INSTALL_SCRIPT} ${WRKSRC}/buildscripts/out/lilypond-${ii} \
		${EXAMPLESDIR}/scripts
.endfor
.for ii in lilypond-font-lock.el lilypond-indent.el lilypond-init.el \
	lilypond-mode.el lilypond-init.el
	${INSTALL_SCRIPT} ${WRKSRC}/elisp/${ii} ${EXAMPLESDIR}/scripts
.endfor
.for ii in lilypond.vim server.el.patch
	${INSTALL_SCRIPT} ${WRKSRC}/${ii} ${EXAMPLESDIR}/scripts
.endfor
	cd ${WRKSRC}/Documentation/topdocs/out && ${TAR} -chf - \
		--exclude=dummy.dep --exclude=CVS --exclude=GNUmakefile . \
		| ${TAR} -xf - -C ${DOCSDIR}

.for ii in ${INFO}
	- ${INSTALL_INFO} ${PREFIX}/info/${ii}.info ${PREFIX}/info/dir
.endfor
.endif
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${ECHO_CMD} "* Look in ${EXAMPLESDIR}/scripts"
	@${ECHO_CMD} "* for needed additions to your .profile"
	@${ECHO_CMD} "* (at least the TEXMF environment variable is required)."

.include <bsd.port.post.mk>

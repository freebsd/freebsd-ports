# New ports collection makefile for:	lilypond
# Date created:				2001-02-10
# Whom:					trevor
# based on NetBSD pkgsrc/print/lilypond
#
# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 17:32:11 rh Exp $
# $FreeBSD$
#

PORTNAME=	lilypond
PORTVERSION=	2.0.1
CATEGORIES=	print audio
MASTER_SITES=	ftp://ftp.lilypond.org//pub/LilyPond/v2.0/

MAINTAINER=	atamaniuk@frobs.net
COMMENT=	The GNU music typesetter

BUILD_DEPENDS=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

MAN1=	abc2ly.1 as2text.1 convert-ly.1 etf2ly.1 lilypond.1 lilypond-bin.1 \
	lilypond-book.1 midi2ly.1 mup2ly.1 musedata2ly.1 pmx2ly.1
INFO=		lilypond lilypond-internals

GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	YES
USE_PYTHON=	YES
MAKEFILE=	GNUmakefile

CONFIGURE_ARGS+=	--with-kpathsea-include=${PREFIX}/include \
			--with-kpathsea-lib=${PREFIX}/lib

# inform kpathsea.h of getopt-prototype version
CFLAGS+=	-D__GNU_LIBRARY__

.include <bsd.port.pre.mk>
.if !defined(WITHOUT_PFA_FONTS)
BUILD_DEPENDS+=	${PREFIX}/bin/mftrace:${PORTSDIR}/print/pktrace
MAKE_ENV+=	MAKE_PFA_FILES=1
ALL_TARGET=	all	# XXX pfa-fonts
.endif

.if ${OSVERSION} < 500000
USE_GCC=	3.3
OLD_CPP_INCLUDEDIR=	/usr/include/g++
CONFIGURE_ENV+=	"CPPFLAGS=$${CPPFLAGS} -idirafter ${OLD_CPP_INCLUDEDIR}"
.endif

SCRIPTS_ENV+=	PORTVERSION=${PORTVERSION}

pre-everything::
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} Pausing ten seconds--press control-C to cancel the build.
	@sleep 10

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}/scripts
	cd ${WRKSRC}/input ; \
	${TAR} -chf - --exclude=out --exclude=CVS --exclude=GNUmakefile . | \
		${TAR} -xf - -C ${EXAMPLESDIR};\
	${FIND} ${EXAMPLESDIR} -name "out" | xargs ${RM} -rf ;\
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

.for file in ${INFO}
	${INSTALL_DATA} ${WRKSRC}/Documentation/user/out/${file}.info \
		${PREFIX}/info/
	install-info ${PREFIX}/info/${file}.info ${PREFIX}/info/dir
.endfor
.endif
	${ENV} PKG_PREFIX=${PREFIX} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
#	${ENV} PATH=${LOCALBASE}/bin:${PREFIX}/bin:${PATH} \
#	TEXMF="{${DATADIR}/${PORTVERSION}},"`kpsexpand  \\$$TEXMF`"}" texhash

	@${ECHO_CMD} "* Look in ${EXAMPLESDIR}/scripts for needed additions to"
	@${ECHO_CMD} "* your .profile (at least the TEXMF environment variable"
	@${ECHO_CMD} "* is required)."

.include <bsd.port.post.mk>

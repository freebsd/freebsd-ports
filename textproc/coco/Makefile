# New ports collection makefile for:	files except executables for mule 2.3@19.34
# Version required:	2.3@19.34
# Date created:		7 July 1997
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.36 1999/01/23 14:28:27 simokawa Exp $
#

DISTNAME=	mule-2.3
PKGNAME=	mule-common-2.3
CATEGORIES=	editors japanese
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.mei.co.jp/archive/free/gnu/emacs/Mule/ \
		ftp://ftp.iij.ad.jp/pub/misc/mule/ \
		http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/mule/
DISTFILES=	emacs-19.34b.tar.gz mule-2.3-19.34.patch-981002.tar.gz

PATCH_SITES=	ftp://etlport.etl.go.jp/pub/mule/
PATCHFILES=	mule-23-1934-alpha01.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

.for dir in 	chinese/mule-wnn4 \
		editors/mule \
		japanese/mule-canna+sj3+wnn4 \
		japanese/mule-canna+sj3+wnn6 \
		japanese/mule-canna+sj3 \
		japanese/mule-canna+wnn4 \
		japanese/mule-canna+wnn6 \
		japanese/mule-canna \
		japanese/mule-sj3+wnn4 \
		japanese/mule-sj3+wnn6 \
		japanese/mule-sj3 \
		japanese/mule-wnn4 \
		japanese/mule-wnn6 \
		korean/mule-wnn4
.if exists(${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work/.install_done)
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work
.elif exists(${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work/.build_done)
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work
.endif
.endfor
WRKSRC= ${WRKDIR}/emacs-19.34
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/mule.sh

.if !defined(WRKDIR)
.if defined(PACKAGE_BUILDING)
# XXX
WRKDIR=	${WRKDIRPREFIX}${.CURDIR}/../mule/work
pre-build:
	@cd ${.CURDIR}/../mule; make
.else
BROKEN=		You should build install one of the other mule ports first
.endif
.endif

INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
TMPPLIST=	${WRKDIR}/.PLIST.mktmp-${PKGNAME}
EMACS_ARCH=	${MACHINE_ARCH}--freebsd
PLIST_SUB=	EMACS_VERSION=19.34 EMACS_ARCH=${EMACS_ARCH}

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
EMACS_PREFIX=	mule
EMACS_EXECUTABLE =	mule
CONFIGURE_ARGS=	${EMACS_ARCH} --with-executable=${EMACS_EXECUTABLE} \
		--with-emacs-prefix=${EMACS_PREFIX} \
		--with-terminal-face \
		--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
STRIP=
MAN1=		coco.1 ctags.1 etags.1 m2ps.1 emacs.1 mule.1

INSTALL_TARGET=	install-arch-indep

COMP_ELC=	egg.elc wnn-egg.elc sj3-client.elc sj3-egg.elc canna.elc
ELC_DIR=	../lisp

# ORIGINAL, MEW_ORG_PATCH and MEW_PATCH are used for debugging.
#
#   ORIGINAL: original mule 2.3 based on emacs 19.34
#   MEW_ORG_PATCH: apply mew's patches to original mule (http://www.mew.org)
#   MEW_PATCH: apply mew's patch after apply Mr. Katayama's patches
post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/mule-2.3-19.34.patch-981002.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${CP} ${FILESDIR}/unexfreebsd.c ${WRKSRC}/src
.if !defined(ORIGINAL) && !defined(MEW_ORG_PATCH)
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/takana-19.34.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${MKDIR} ${WRKSRC}/lisp/its
	${CP} ${WRKDIR}/lisp/its/* ${WRKSRC}/lisp/its/
.endif

.if !defined(ORIGINAL)
post-patch:
.if !defined(MEW_ORG_PATCH)
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/patch-19.34
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/Mule-2.3-19.34.patch
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/extra.patch
.if defined(MEW_PATCH)
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/egg.el-19.34.patch-for_katayama
.endif
.else
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/egg.el-19.34.patch
.endif
.if defined(MEW_PATCH) || defined(MEW_ORG_PATCH)
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/canna.el-19.34.patch
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/sj3-egg.el.patch
.endif
.endif

pre-build:
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/etc/DOC* ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-19.34.*

post-build:
# bytecompile elisps for Japanese input method
	for file in ${COMP_ELC}; do \
		target="$$target ${ELC_DIR}/$$file"; \
	done; \
	cd ${WRKSRC}/src; \
	./temacs -batch -l mule-inst.el $$target

post-install:
# note that any2ps rcs-checkin are scripts
.for file in b2m coco ctags emacsclient etags m2ps
	strip ${PREFIX}/bin/${file}
.endfor
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	if [ ! -f ${PREFIX}/share/mule/19.34/info/dir ]; then \
	  ${MKDIR} ${PREFIX}/share/mule/19.34/info; \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/share/mule/19.34/info/dir; \
	fi
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# Our makeinfo can't handle files with Japanese characters. :<
	install-info --section="The Emacs editor and associated tools" --entry="* Antenews-jp: (antenews-jp).	Version 19 Antenews. (Japanese)" ${PREFIX}/info/antenews-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Mule: (mule).			Multilingual Enhancement to GNU Emacs." ${PREFIX}/info/mule ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Mule-jp: (mule-jp).		Multilingual Enhancement to GNU Emacs. (Japanese)" ${PREFIX}/info/mule-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Egg-jp: (egg-jp).		Japanese/Chinese Inputting Method. (Japanese)" ${PREFIX}/info/egg-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Canna-jp: (canna-jp).		Another Japanese Inputting Method. (Japanese)" ${PREFIX}/info/canna-jp ${PREFIX}/info/dir
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
	if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file."; \
		${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT}; \
		${ECHO} '#echo -n " Mule"' >> ${STARTUP_SCRIPT}; \
		${ECHO} 'if [ -d /var/run/emacs/lock ]; then' >> ${STARTUP_SCRIPT}; \
		${ECHO} '     rm -f /var/run/emacs/lock/*' >> ${STARTUP_SCRIPT}; \
		${ECHO} "else" >> ${STARTUP_SCRIPT}; \
		${ECHO} "     mkdir -p /var/run/emacs/lock" >> ${STARTUP_SCRIPT}; \
		${ECHO} "fi" >> ${STARTUP_SCRIPT} ; \
		${ECHO} "chmod 1777 /var/run/emacs/lock${lockdir}" >> ${STARTUP_SCRIPT} ; \
		chmod 755 ${STARTUP_SCRIPT} ;				\
		chown bin.bin ${STARTUP_SCRIPT};			\
	fi

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.mk>

# New ports collection makefile for:	dgd
# Version required:	1.0.9
# Date created:		23 August 1994
# Whom:			adam
#

DISTNAME=	dgd-1.0.9
DISTFILES=	${DISTNAME}.tar.gz
CATEGORIES=	networking languages

MAINTAINER=	adam@veda.is

_PATCHFILES=	1.0.9-1.0.9.1.gz
.if defined(MASTER_SITE_OVERRIDE)
PATCHSITE:=	${MASTER_SITE_OVERRIDE}
.else
PATCHSITE=	epsilon.me.chalmers.se:
NCFTPFLAGS=
.endif
.if ${_PATCHFILES} != ""
_PATCH_COOKIE=	${.CURDIR}/work/._patch_done
PATCHLIST=	${.CURDIR}/work/.patchlist
PATCHLEVEL=	.`echo ${_PATCHFILES} | sed 's/^.*\.\(.*\)\.gz$$/\1/'`
.endif
WRKSRC=		${WRKDIR}/dgd/src

pre-fetch:
	@if [ ! -d ${DISTDIR}/${DISTNAME} ]; then mkdir -p ${DISTDIR}/${DISTNAME}; fi
	@if [ ! -f ${DISTDIR}/${DISTNAME}.tar.gz ]; then \
		echo ">> Fetching distribution file from remote site..."; \
		${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}${DISTNAME}.tar.gz \
        		&& mv ${DISTNAME}.tar.gz ${DISTDIR}; \
	fi
.if defined(MASTER_SITE_OVERRIDE)
	@for file in ${_PATCHFILES}; do \
		if [ ! -f ${DISTDIR}/${DISTNAME}/$$file ]; then \
			echo ">> Fetching patch $$file from remote site...";  \
			${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}${DISTNAME}/$$file \
				&& mv $$file ${DISTDIR}/${DISTNAME}; \
	    	fi \
	 done
.else
	@for file in ${_PATCHFILES}; do \
		if [ ! -f ${DISTDIR}/${DISTNAME}/$$file ]; then \
			echo ">> Fetching patch $$file from remote site...";  \
			${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}patches/$$file \
				&& mv patches/$$file ${DISTDIR}/${DISTNAME}; \
	    	fi \
	 done
.endif

# Need to determine whether all author-supplied patches are correctly applied
### not yet implemented

.if ${_PATCHFILES} != ""
pre-patch: ${_PATCH_COOKIE}
	@find -X ${WRKDIR}/dgd -name '*.orig' -print | xargs rm -f

${_PATCH_COOKIE}:
	@echo "===>  Updating to ${DISTNAME}${PATCHLEVEL}"
	@cd ${DISTDIR}/${DISTNAME}; \
		gzcat ${_PATCHFILES} | patch -d ${WRKDIR} --quiet -E -p0
	@touch -f ${_PATCH_COOKIE}
.endif

do-install:
	@chown -R mud.mud ${WRKDIR}/dgd
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' pkg/PLIST` \
		| tar -C ${PREFIX} -xpf -

.if !defined(DO_PACKAGE)
package:
	@${MAKE} ${.MAKEFLAGS} 'PKG_CMD= WRKDIR=${WRKDIR} ${PKG_CMD}' \
	    PKGNAME=${DISTNAME}${PATCHLEVEL} NO_INSTALL= DO_PACKAGE= package
.endif

.include <bsd.port.mk>

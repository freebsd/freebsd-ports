# New ports collection makefile for:	dgd
# Version required:	1.0.8
# Date created:		23 August 1994
# Whom:			adam
#

DISTNAME=	dgd-1.0.8
DISTFILES=	${DISTNAME}.tar.gz ${DISTNAME}/1.0.8-1.0.8.1.gz \
		${DISTNAME}/1.0.8.1-1.0.8.2.gz ${DISTNAME}/1.0.8.2-1.0.8.3.gz \
		${DISTNAME}/1.0.8.3-1.0.8.4.gz ${DISTNAME}/1.0.8.4-1.0.8.5.gz \
		${DISTNAME}/1.0.8.5-1.0.8.6.gz ${DISTNAME}/1.0.8.6-1.0.8.7.gz
PATCHFILES=	1.0.8-1.0.8.1.gz 1.0.8.1-1.0.8.2.gz 1.0.8.2-1.0.8.3.gz \
		1.0.8.3-1.0.8.4.gz 1.0.8.4-1.0.8.5.gz 1.0.8.5.gz-1.0.8.6.gz \
		1.0.8.6-1.0.8.7.gz
PATCHSITE=	epsilon.me.chalmers.se
NCFTPFLAGS=
PATCH_COOKIE=	${.CURDIR}/work/.patch_done
PATCHLIST=	${.CURDIR}/work/.patchlist
PATCHLEVEL=	`tail -1 ${PATCHLIST} | sed 's/^.*\.\(.*\)\.gz$$/\1/'`
WRKSRC=		${WRKDIR}/dgd/src
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-r ${PKGDIR}/REQ

pre-fetch:
	@if [ ! -d ${DISTDIR}/${DISTNAME} ]; then mkdir -p ${DISTDIR}/${DISTNAME}; fi
	@if [ ! -f ${DISTDIR}/${DISTNAME}.tar.gz ]; then \
		echo ">> Fetching distribution file from remote site..."; \
		${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}:${DISTNAME}.tar.gz \
        		&& mv ${DISTNAME}.tar.gz ${DISTDIR}; \
	fi
	@for file in ${PATCHFILES}; do \
		if [ ! -f ${DISTDIR}/${DISTNAME}/$$file ]; then \
			echo ">> Fetching patch $$file from remote site...";  \
			${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}:patches/$$file \
				&& mv patches/$$file ${DISTDIR}/${DISTNAME}; \
	    	fi \
	 done

# Need to determine whether all author-supplied patches are correctly applied
### not yet implemented

pre-configure: extract ${PATCH_COOKIE}
	@find -X ${WRKDIR}/dgd -name '*.orig' -print | xargs rm -f

${PATCHLIST}:
	@cd ${DISTDIR}/${DISTNAME}; \
		ls *.[0-9].gz *.[0-9][0-9].gz \
		2>/dev/null >${PATCHLIST}

${PATCH_COOKIE}: ${PATCHLIST}
	@if [ -s ${PATCHLIST} ]; then \
		echo "===>  Updating to ${DISTNAME}.${PATCHLEVEL}"; \
		cd ${DISTDIR}/${DISTNAME}; \
		gzcat `cat ${PATCHLIST}` | patch -d ${WRKDIR} --quiet -E -p0; \
	fi
	@touch -f ${PATCH_COOKIE}

install: all
	@chown -R mud.mud ${WRKDIR}/dgd
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' pkg/PLIST` \
		| tar -C /usr/local -xpf -

.include <bsd.port.mk>

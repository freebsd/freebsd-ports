# New ports collection makefile for:	dgd
# Version required:	1.0.8
# Date created:		23 August 1994
# Whom:			adam
#

DISTNAME=	dgd-1.0.8
PATCHFILES=	1.0.8-1.0.8.1.gz 1.0.8.1-1.0.8.2.gz 1.0.8.2-1.0.8.3.gz
PATCHSITE=	epsilon.me.chalmers.se
NCFTPFLAGS=
PATCH_COOKIE=	${.CURDIR}/work/.patch_done
PATCHLIST=	${.CURDIR}/work/.patchlist
PATCHLEVEL=	`tail -1 ${PATCHLIST} | sed 's/^.*\.\(.*\)\.gz$$/\1/'`
WRKSRC=		${WRKDIR}/dgd/src
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-r ${PKGDIR}/REQ

### rely on DISTFILES being a single filename

pre-fetch:
	@if [ ! -d ${DISTDIR}/${DISTNAME} ]; then mkdir -p ${DISTDIR}/${DISTNAME}; fi
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
	    echo ">> Fetching distribution file from remote system..." \
	    ${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}:${DISTFILES} \
        	&& mv ${DISTFILES} ${DISTDIR}; \
	fi
	@for file in ${PATCHFILES}; do \
		if [ ! -f ${DISTDIR}/${DISTNAME}/$$file ]; then \
			echo ">> $$file doesn't seem to exist on this system."; \
			echo ">> Attempting to fetch it from a master site."; \
			if ${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}:patches/$$file; \
			then \
				echo ">> $$file Fetched!" ; \
				mv patches/$$file ${DISTDIR}/${DISTNAME}; \
				break; \
			fi; \
			if [ ! -f ${DISTDIR}/${DISTNAME}/$$file ]; then \
				echo ">> Couldn't fetch it - please try to retreive this";\
				echo ">> file manually into ${DISTDIR}/${DISTNAME} and try again."; \
				exit 1; \
			fi; \
	    	fi \
	 done

# We need to determine whether all author-supplied patches are present
# and whether they are applied correctly
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

bundle: extract
	@echo "===>  Bundling for ${DISTNAME}.${PATCHLEVEL}"
	@if [ -f ${CONFIGURE_COOKIE} ]; then \
		echo ">> WARNING:  This source has been configured and may"; \
		echo ">> produce a tainted distfile!"; \
	fi
	tar -C ${WRKDIR} -cf - dgd | gzip -9 \
		>${DISTDIR}/${DISTNAME}.${PATCHLEVEL}${EXTRACT_SUFX}

install: all
	@chown -R mud.mud ${WRKDIR}/dgd
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' pkg/PLIST` \
		| tar -C /usr/local -xpf -

.include <bsd.port.mk>

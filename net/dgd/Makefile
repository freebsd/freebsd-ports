# New ports collection makefile for:	dgd
# Version required:	1.0.8
# Date created:		23 August 1994
# Whom:			adam
#

DISTNAME=	dgd-1.0.8
HOME_LOCATION=	ftp.lysator.liu.se:~ftp/pub/lpmud/drivers/dgd/dgd-1.0.8
PATCH_LOCATION=	epsilon.me.chalmers.se:~dgd/patches/$@ Password: foo&&bar
PATCH_COOKIE=	${.CURDIR}/work/.patch_done
PATCHLIST=	${.CURDIR}/work/.patchlist
PATCHLEVEL=	`tail -1 ${PATCHLIST} | sed 's/^.*\.\(.*\)\.gz$$/\1/'`
WRKSRC=		${WRKDIR}/dgd/src
PKG_ARGS=	-v -c ${PKGDIR}/COMMENT -d ${PKGDIR}/DESCR -f ${PKGDIR}/PLIST \
		-r ${PKGDIR}/REQ

# We need to determine whether all author-supplied patches are present
# and whether they are applied correctly
### not yet implemented

pre-configure: extract ${PATCH_COOKIE}
	@find -X ${WRKDIR}/dgd -name '*.orig' -print | xargs rm -f

${PATCHLIST}:
	@cd ${DISTDIR}; \
		ls ${DISTNAME}*.[0-9].gz ${DISTNAME}*.[0-9][0-9].gz \
		2>/dev/null >${PATCHLIST}

${PATCH_COOKIE}: ${PATCHLIST}
	@if [ -s ${PATCHLIST} ]; then \
		echo "===>  Updating to ${DISTNAME}.${PATCHLEVEL}"; \
		cd ${DISTDIR}; \
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

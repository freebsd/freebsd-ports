# New ports collection makefile for:	dgd
# Version required:	1.0.9
# Date created:		23 August 1994
# Whom:			adam
#

DISTNAME=	dgd-1.0.9
DISTFILES=	${DISTNAME}.tar.gz
PATCHFILES=	1.0.9-1.0.9.1.gz
MASTER_SITES=	ftp.lysator.liu.se:/pub/lpmud/drivers/dgd/
PATCH_SITES=	ftp.veda.is:/pub/mud/dgd/patches/
CATEGORIES=	networking languages

MAINTAINER=	adam@veda.is

.if ${PATCHFILES} != ""
PATCH_PRFX=	${DISTNAME}/
PATCHLEVEL!=	echo ${PATCHFILES} | sed 's/^.*\.\(.*\)\.gz$$/\1/'
PKGNAME=	${DISTNAME}.${PATCHLEVEL}
.endif
WRKSRC=		${WRKDIR}/dgd/src

pre-patch:
	@ln -fs .. ${WRKSRC}/dgd

post-patch:
	@find -X ${WRKDIR}/dgd -name '*.orig' -print | xargs rm -f

post-build:
	@cd ${WRKSRC}; ${MAKE} install
	@sed '/^@srcdir/s|\.|${WRKDIR}/\.|' <${PKGDIR}/PLIST >${WRKDIR}/PLIST

do-install:
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' pkg/PLIST` \
		| tar -C ${PREFIX} -xpf -

.if !defined(DO_PACKAGE)
package:
#	@${MAKE} ${.MAKEFLAGS} 'PKG_CMD= cd ${WRKDIR}; ${PKG_CMD}' \
	@${MAKE} ${.MAKEFLAGS} 'PKG_ARGS= ${PKG_ARGS} -f ${WRKDIR}/PLIST' \
	    NO_INSTALL= DO_PACKAGE= package
.endif

.include <bsd.port.mk>

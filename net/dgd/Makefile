# New ports collection makefile for:	dgd
# Version required:	1.0.9
# Date created:		23 August 1994
# Whom:			adam
#

DISTNAME=	dgd-1.0.9
DISTFILES=	${DISTNAME}.tar.gz
PATCHFILES=	1.0.9-1.0.9.1.gz
MASTER_SITES=	epsilon.me.chalmers.se:
PATCH_SITES=	epsilon.me.chalmers.se:patches/
NCFTP=		env DOTDIR=${.CURDIR} ncftp
NCFTPFLAGS=	-V2
CATEGORIES=	networking languages

MAINTAINER=	adam@veda.is

.if ${PATCHFILES} != ""
PATCHLEVEL!=	echo ${PATCHFILES} | sed 's/^.*\.\(.*\)\.gz$$/\1/'
PKGNAME=	${DISTNAME}.${PATCHLEVEL}
.endif
WRKSRC=		${WRKDIR}/dgd/src

pre-fetch:
	@ln -f ncftprc .ncftprc

pre-patch:
	@ln -fs .. ${WRKSRC}/dgd

post-patch:
	@find -X ${WRKDIR}/dgd -name '*.orig' -print | xargs rm -f

post-build:
	@cd ${WRKSRC}; ${MAKE} install

do-install:
	@chown -R mud.mud ${WRKDIR}/dgd
	@tar -C ${WRKDIR} -cf - `grep '^dgd/' pkg/PLIST` \
		| tar -C ${PREFIX} -xpf -

.if !defined(DO_PACKAGE)
package:
	@${MAKE} ${.MAKEFLAGS} 'PKG_CMD= WRKDIR=${WRKDIR} ${PKG_CMD}' \
	    NO_INSTALL= DO_PACKAGE= package
.endif

.include <bsd.port.mk>

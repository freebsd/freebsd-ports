# New ports collection makefile for:   linux-realplayer
# Version required:    5.0
# Date created:        31 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id$
#

DISTNAME=	rv50_linux20
PKGNAME=	linux-realplayer-5.0
CATEGORIES=	audio
MASTER_SITES=	"Fetch must be performed manually"

MAINTAINER=	kkennawa@physics.adelaide.edu.au

RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

ONLY_FOR_ARCHS= i386
NO_CDROM=       "Redistribution not allowed"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rvplayer5.0/

LIBFILES=	libdecdnet.so libra14_4.so libra28_8.so libradnet.so \
		librarv10.so librasipr.so librv10dec.so librvcore.so \
		librvplayer.so

DATAFILES=	License.txt Mailcap Mime.types RAObserver.class \
		RAPlayer.class rvplayer.ad

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}.tar.gz)
IGNORE=		may not be automatically fetched due to licensing\
		restrictions.  You MUST fetch the source manually after\
		reading and agreeing to the license at:\
		http://www.real.com/products/player/50player/downloadrealplayer.html?wp=dl1198&src=download\
		- once ${DISTFILES}.tar.gz has been downloaded, move it to\
		${DISTDIR} and then restart this build.
.endif

do-install:

	${MKDIR} ${PREFIX}/lib/rvplayer5.0/
	${MKDIR} ${PREFIX}/share/rvplayer5.0/

.for i in ${DATAFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/lib/rvplayer5.0/
.endfor

.if !defined(NOPORTSDOCS)
	${MKDIR} ${PREFIX}/share/doc/rvplayer5.0/
	${CP} -rp ${WRKSRC}/README ${WRKSRC}/index.htm ${WRKSRC}/doc/ \
		 ${PREFIX}/share/doc/rvplayer5.0/
.endif

.for i in ${LIBFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/lib/rvplayer5.0/
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/rvplayer ${PREFIX}/bin/
	/usr/bin/brandelf -t Linux ${PREFIX}/bin/rvplayer

	${INSTALL_DATA} ${WRKSRC}/welcome.rm ${PREFIX}/share/rvplayer5.0/

	@echo ---------------------------------------------------------------
	@echo You must add ${PREFIX}/lib/rvplayer5.0 to your
	@echo LD_LIBRARY_PATH environment variable to use RealPlayer 5.0.
	@echo
	@echo To use the Netscape plugin, you must have a Linux version of
	@echo netscape \(e.g., ${PORTSDIR}/www/linux-netscape4/\) - see
	@echo ${PREFIX}/share/doc/rvplayer5.0/plugin.html for instructions.
	@echo
	@echo To use rvplayer as an external helper app for Netscape \(any
	@echo version\), follow the instructions in
	@echo ${PREFIX}/share/doc/rvplayer5.0/browser.htm.
	@echo ---------------------------------------------------------------

.include <bsd.port.post.mk>

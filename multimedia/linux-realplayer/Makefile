# New ports collection makefile for:   linux-realplayer
# Date created:        31 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	linux-realplayer
PORTVERSION=	5.0
CATEGORIES=	audio linux
MASTER_SITES=	# fetch manually
DISTNAME=	rv50_linux20

MAINTAINER=	kris@FreeBSD.org

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS= i386
NO_CDROM=       "Redistribution not allowed"
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rvplayer5.0/

STRIP=		# Linux binary should not be stripped by INSTALL_PROGRAM as it uses /usr/bin/strip which then brands the binary as a FreeBSD ELF one.

LIBFILES=	libdecdnet.so libra14_4.so libra28_8.so libradnet.so \
		librarv10.so librasipr.so librv10dec.so librvcore.so \
		librvplayer.so

DATAFILES=	License.txt Mailcap Mime.types RAObserver.class \
		RAPlayer.class rvplayer.ad

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}.tar.gz)
IGNORE=		may not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the Linux ELF version after\
		reading and agreeing to the license at:\
		http://proforma.real.com/real/player/blackjack.html \
		- once ${DISTFILES} has been downloaded, move it to\
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
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/lib/rvplayer5.0/
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/rvplayer ${PREFIX}/bin/
	/compat/linux/usr/bin/strip ${PREFIX}/bin/rvplayer
	/usr/bin/brandelf -t Linux ${PREFIX}/bin/rvplayer

	${INSTALL_DATA} ${WRKSRC}/welcome.rm ${PREFIX}/share/rvplayer5.0/

	@${ECHO_MSG} ---------------------------------------------------------------
	@${ECHO_MSG} You must add ${PREFIX}/lib/rvplayer5.0 to your
	@${ECHO_MSG} LD_LIBRARY_PATH environment variable to use RealPlayer 5.0.
	@${ECHO_MSG}
	@${ECHO_MSG} To use the Netscape plugin, you must have a Linux version of
	@${ECHO_MSG} netscape \(e.g., ${PORTSDIR}/www/linux-netscape4/\) - see
	@${ECHO_MSG} ${PREFIX}/share/doc/rvplayer5.0/plugin.html for instructions.
	@${ECHO_MSG}
	@${ECHO_MSG} To use rvplayer as an external helper app for Netscape \(any
	@${ECHO_MSG} version\), follow the instructions in
	@${ECHO_MSG} ${PREFIX}/share/doc/rvplayer5.0/browser.htm.
	@${ECHO_MSG} ---------------------------------------------------------------

.include <bsd.port.post.mk>

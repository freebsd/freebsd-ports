# New ports collection makefile for:    wingz
# Date created:         Wed Nov 27 09:15:10 CST 1996
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	wingzpro
PORTVERSION=	311
CATEGORIES=	math linux
MASTER_SITES=	netu
EXTRACT_ONLY=

MAINTAINER=	mi@aldan.algebra.com

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_PACKAGE=	"nothing to build. commercial software"

do-fetch:
	#
	# this is another one of those commercial pieces of software,
	# that require you to download manually after "registering".
	# Please, proceeed to
	#	http://www.wingz-us.com/iisg_main/downloads.html
	# download the ${DISTFILES} and save it to ${DISTDIR}.
	#

do-install:
	${TAR} -xzp -C ${X11BASE} -f ${DISTDIR}/${DISTFILES}
	${SED} 's%_X11BASE_%${X11BASE}%' \
		< ${FILESDIR}/Wingz3 \
		> ${X11BASE}/bin/Wingz3
	${CHMOD} 755 ${X11BASE}/bin/Wingz3

.include <bsd.port.mk>

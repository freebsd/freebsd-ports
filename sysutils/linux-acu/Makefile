# New ports collection makefile for:	linux-acu
# Date created:		Tue Jun 25 02:24:41 GMT 2002
# Whom:			Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	acu
PORTVERSION=	2.0
CATEGORIES=	sysutils
MASTER_SITES=	# fetch manually
PKGNAMEPREFIX=	linux-
DISTNAME=	Linux-ACU-Driver-v${PORTVERSION}

MAINTAINER=	matt@peterson.org

RUN_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

.include <bsd.port.pre.mk>

#.if ${OSVERSION} < 460000
#BROKEN=         "${PORTNAME} is not available for your version of FreeBSD.  Please upgrade."
#.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the tarball after\
		reading and agreeing to the license at:\
		http://www.cisco.com/pcgi-bin/tablebuild.pl/aironet-utils-linux\
		- once '${DISTNAME}${EXTRACT_SUFX}' has been downloaded, move it to\
		${DISTDIR} and then restart this build.
.endif

ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_CDROM=	"Redistribution not allowed"

do-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${LINUXBASE}/proc/aironet
	@${INSTALL} ${WRKSRC}/utilities/acu ${PREFIX}/bin

post-install:
	@${ECHO} "acu installed under ${PREFIX}/bin"
	@${ECHO} "notes: acu will only run from the root super-user account"
	@${ECHO} "       to allow root access to your X session,"
	@${ECHO} "       run 'xhost localhost' or use sudo."
	@${ECHO} "       acu will not run with linprocfs since it needs to see:"
	@${ECHO} "	        ${LINUXBASE}/proc/aironet""
	@${ECHO} "	acu annoyingly creates"
	@${ECHO} "		/compat/linux/etc/eth2.cfg"
	@${ECHO} "	and will use that over the current card's settings."

.include <bsd.port.post.mk>

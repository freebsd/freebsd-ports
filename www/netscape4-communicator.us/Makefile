# ex:ts=8
# New ports collection makefile for:	netscape (full communicator version)
# Version required:     4.04-us
# Date created:         14 Feb 1998
# Whom:                 obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.8 1999/01/13 04:00:08 scrappy Exp $
#

DISTNAME=	communicator-v407-us.x86-unknown-linux2.0_libc5
PKGNAME=	netscape-communicator-4.07.us
CATEGORIES=	www

MAINTAINER=	obrien@FreeBSD.ORG

Y2K=		http://home.netscape.com/products/year2000/faq/client.html

RUN_DEPENDS=	/compat/linux/lib/ld-linux.so.1:${PORTSDIR}/emulators/linux_lib

RESTRICTED=	"Commerial & USA ITAR export restrictions"
ONLY_FOR_ARCHS=	i386

NO_FETCH=	yes
NO_BUILD=	Yes

WRKSRC=		${WRKDIR}/communicator-v407.x86-unknown-linux2.0
NDIR=		${PREFIX}/lib/netscape.us
BINDIR=		${PREFIX}/bin

.include <bsd.port.pre.mk>

# Need to define USA_RESIDENT to YES or NO
.if !defined(USA_RESIDENT) || (${USA_RESIDENT} != YES && ${USA_RESIDENT} != yes && ${USA_RESIDENT} != NO && ${USA_RESIDENT} != no)
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES, if you are USA or 
	@${ECHO} Canadian resident, in order to build this package.
	@${ECHO} There is no version of this port for NON-USA and NON-Canadian users.
	@${ECHO}
	@false
#
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES || ${USA_RESIDENT} == yes

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='You must manually obtain ${DISTNAME}${EXTRACT_SUFX} distribution and place it in ${DISTDIR}.'
.endif

.else
pre-fetch:
	@${ECHO}
	@${ECHO} There is no version of this port for NON-USA and NON-Canadian users.
	@${ECHO}
	@false
.endif
.endif

do-install:
	cd ${WRKSRC} && \
		yes "" | LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} -f ${NDIR}/netscape ${NDIR}/communicator-4.07.us.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-4.07.us
	${LN} -sf communicator-4.07.us ${BINDIR}/communicator-4.us
	${LN} -sf communicator-4.07.us ${BINDIR}/netscape.us
	if [ ! -f ${NDIR}/mailcap ] ; then \
		${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/netscape-dynMotif
	${RM} -rf ${NDIR}/libnullplugin-dynMotif.so
	${RM} -rf ${NDIR}/movemail-src
	chown -R ${BINOWN}.${BINGRP} ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.post.mk>

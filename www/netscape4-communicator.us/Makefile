# ex:ts=8
# New ports collection makefile for:	netscape (full communicator version)
# Version required:     4.04-us
# Date created:         14 Feb 1998
# Whom:                 obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.2 1998/02/14 23:35:48 obrien Exp $
#

DISTNAME=	communicator_pro-v405-us.x86-unknown-linux2.0
PKGNAME=	netscape-communicator-4.05.us
CATEGORIES=	www

MAINTAINER=	obrien@FreeBSD.ORG

RESTRICTED=	"Commerial & USA ITAR export restrictions"

NO_FETCH=	yes
NO_BUILD=	Yes

WRKSRC=		${WRKDIR}/communicator-v405.x86-unknown-linux2.0
NDIR=		${PREFIX}/lib/netscape.us
BINDIR=		${PREFIX}/bin

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
#
pre-fetch:
	@(if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	${ECHO} You must manually obtain ${DISTNAME}${EXTRACT_SUFX} ; \
	${ECHO} distribution and placed it in ${DISTDIR}. ; \
	false ; \
	fi )
.else
pre-fetch:
	@${ECHO}
	@${ECHO} There is no version of this port for NON-USA and NON-Canadian users.
	@${ECHO}
	@false
.endif
.endif

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	mv -f ${NDIR}/netscape ${NDIR}/communicator-pro-4.05.us.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-pro-4.05.us
	ln -sf communicator-pro-4.05.us ${BINDIR}/communicator-4.us
	ln -sf communicator-pro-4.05.us ${BINDIR}/netscape.us
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	rm -rf ${NDIR}/netscape-dynMotif
	rm -rf ${NDIR}/libnullplugin-dynMotif.so
	rm -rf ${NDIR}/movemail-src
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>

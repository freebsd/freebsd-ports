# ex:ts=8
# New ports collection makefile for:	netscape (full communicator version)
# Version required:     4.04-us
# Date created:         14 Feb 1998
# Whom:                 obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.1.1.1 1998/02/11 03:31:30 obrien Exp $
#

DISTNAME=	communicator-v404-us.x86-unknown-linux2.0
PKGNAME=	netscape-communicator-4.04.us
CATEGORIES=	www

MAINTAINER=	obrien@FreeBSD.ORG

RESTRICTED=	"Commerial & USA ITAR export restrictions"

NO_FETCH=	yes
NO_WRKSUBDIR=	Yes
NO_BUILD=	Yes

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
	@${ECHO} You must manually obtain ${DISTNAME}${EXTRACT_SUFX}
	@${ECHO} distribution and placed it in ${DISTDIR}.
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
	mv -f ${NDIR}/netscape ${NDIR}/communicator-4.04.us.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-4.04.us
	ln -sf communicator-4.04 ${BINDIR}/communicator-4.us
	ln -sf communicator-4 ${BINDIR}/netscape.us
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	rm -rf ${NDIR}/movemail-src
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>

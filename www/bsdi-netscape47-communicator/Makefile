# New ports collection makefile for: Netscape Communicator for BSDI BSD/OS
# Date created:		10 May 2000
# Whom:			Trevor Johnson <trevor@jpj.net>
# based on work by thepish and girgen@partitur.se
#
# $FreeBSD$
#

PORTNAME=	bsdi-netscape-${BROWSER}

MAINTAINER=	trevor@FreeBSD.org

ONLY_FOR_ARCHS=	i386

NETSCAPE_DIST_ARCH=	unsupported/bsdi21
NETSCAPE_DIST_TAG=	x86-bsdi-bsd2

# don't overwrite the FreeBSD port's shell script wrapper in ${PREFIX}/bin
BROWSER_ARC=	${BROWSER}-bsdi

MAILCAP=	${.CURDIR}/../bsdi-netscape47-communicator/files/mailcap
NSUBDIR=	lib/netscape-bsdi

# don't require a.out libraries
WITHOUT_AOUT=		yes

pre-fetch:
	@${ECHO} "************************************************************"
	@${ECHO} "None of the Software or underlying information or technology"
	@${ECHO} "may be downloaded or otherwise exported or re-exported (i)"
	@${ECHO} "into (or to a national or resident of) Cuba, Iraq, Libya,"
	@${ECHO} "Sudan, North Korea, Iran, Syria or any other country to"
	@${ECHO} "which the U.S.  has embargoed goods; or (ii) to anyone on"
	@${ECHO} "the U.S.  Treasury Department's list of Specially Designated"
	@${ECHO} "Nationals or the U.S.  Commerce Department's Table of Denial"
	@${ECHO} "Orders.  By downloading or using the Software, you are"
	@${ECHO} "agreeing to the foregoing and you are representing and"
	@${ECHO} "warranting that you are not located in, under the control"
	@${ECHO} "of, or a national or resident of any such country or on"
	@${ECHO} "any such list."
	@${ECHO} "************************************************************"

.include "../netscape47-communicator/Makefile"

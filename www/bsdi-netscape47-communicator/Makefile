# New ports collection makefile for: Netscape Communicator for BSDI BSD/OS
# Date created:		10 May 2000
# Whom:			Trevor Johnson <trevor@jpj.net>
# based on work by thepish and girgen@partitur.se
#
# $FreeBSD$
#

PORTNAME=	bsdi-netscape-${BROWSER}
PORTVERSION=	4.75

MAINTAINER=	trevor@FreeBSD.org

FORBIDDEN=	"buffer overflow in password field of HTML forms,\
		reported by Michal Zalewski and fixed in 4.76--example at \
		http://people.freebsd.org/~trevor/hostile-page.html ; \
		also has GIF comment bug--see \
		http://dividuum.de/security/netscape/ "

ONLY_FOR_ARCHS=	i386

DISTFILES=	${BROWSER}-v475-us.${NETSCAPE_DIST_TAG}.tar.gz
INFILE_HEAD=	'Communicator,4.75.0.20000814'
BROWSER_VER=	4.75
WRKSRC=		${WRKDIR}/${BROWSER}-v475.${NETSCAPE_DIST_TAG}

NETSCAPE_DIST_ARCH=	unsupported/bsdi21
NETSCAPE_DIST_TAG=	x86-bsdi-bsd2

# don't overwrite the FreeBSD port's shell script wrapper in ${PREFIX}/bin
BROWSER_ARC=	${BROWSER}-bsdi

MAILCAP=	${.CURDIR}/../bsdi-netscape47-communicator/files/mailcap
NSUBDIR=	lib/netscape-bsdi

# don't require a.out libraries
WITHOUT_AOUT=		yes

pre-fetch:
	@${CAT} ${PKGMESSAGE}

.include "../netscape47-communicator/Makefile"

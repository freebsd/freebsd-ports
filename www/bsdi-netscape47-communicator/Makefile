# New ports collection makefile for: Netscape Communicator for BSDI BSD/OS
# Date created:		10 May 2000
# Whom:			Trevor Johnson <trevor@jpj.net>
# based on work by thepish and girgen@partitur.se
#
# $FreeBSD$
#

PORTNAME=	bsdi-netscape-${BROWSER}
PORTVERSION=	${BROWSER_VER}
CATEGORIES=	www

.if !defined(MASTER_SITES)
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/english/4.73/unix/unsupported/bsdi21/complete_install/ \
		ftp://ftp.sunet.se/pub/www/Netscape/communicator/english/4.73/unix/unsupported/bsdi21/complete_install/
.endif

DISTFILES=	${BROWSER}-v473-export.x86-bsdi-bsd2.tar.gz

MAINTAINER=	trevor@jpj.net

NO_FORTIFY=	"frozen until further notice--http://www.fortify.net/latest_main.html"

RUN_DEPENDS=	netscape:${PORTSDIR}/www/netscape-wrapper

ONLY_FOR_ARCHS=	i386

# don't overwrite the FreeBSD port's shell script wrapper in ${PREFIX}/bin
BROWSER_ARC=	${BROWSER}-bsdi

MASTERDIR=	${.CURDIR}/../netscape4-communicator
WRKSRC=		${WRKDIR}/${BROWSER}-v473.x86-bsdi-bsd2

BROWSER_VER=	4.73
#	taken from ,${BLDVERS} in ns-install
INFILE_HEAD?=	'Communicator,4.73.0.20000502'
NO_AUTOADMIN=	yes

MAILCAP=	${.CURDIR}/../bsdi-netscape47-communicator/files/mailcap
NSUBDIR=	lib/netscape-bsdi

PRE_MK_INCLUDED=	yes
# don't require a.out libraries
WITHOUT_AOUT=		yes

.include "${MASTERDIR}/Makefile"

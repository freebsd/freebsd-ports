# New ports collection makefile for: netscape (communicator suite)
# Date created:		24 Feb 1997
# Whom:			thepish
#
# $FreeBSD$
#

PORTNAME?=	netscape-${BROWSER_ARC}
PORTVERSION?=	${DEFAULT_PORTVERSION}

.if !defined(_PREMKINCLUDED)
.include <bsd.port.pre.mk>
.endif
.if ${ARCH} == "alpha"
DEFAULT_PORTVERSION?=	4.77
.else
DEFAULT_PORTVERSION?=	4.76
.endif

MASTER_SITES=	ftp://ftp.netscape.com/pub/${NETSCAPE_DIST_SUBDIR}/
.if ${ARCH} != "alpha"
MASTER_SITES+=	ftp://ftp.bu.edu/pub/mirrors/ftp.netscape.com/pub/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.cuhk.edu.hk/pub/www/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.spin.ad.jp/pub/WWW/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://sunsite.sut.ac.jp/pub/archives/WWW/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.kmitl.ac.th/pub/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.tuwien.ac.at/z134/infosys/browsers/netscape/pub/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.euronet.be/pub/mirror/ftp.netscape.com/pub/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://sunsite.cnlab-switch.ch/mirror/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.uni-heidelberg.de/pub/Netscape/pub/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.darenet.dk/mirrors/ftp2.netscape.com/pub/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.cica.es/pub5/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.calvacom.fr/pub1/browser/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.ciril.fr/pub1/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.uniroma2.it/Netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.nluug.nl/vol/2/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.ntnu.no/pub/www/Netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://sunsite.uio.no/pub/network/web/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.man.poznan.pl/vols/vol1/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.sunet.se/pub/www/Netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.uakom.sk/pub/WWW/Netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.hi.is/pub/mirrors/ftp.netscape.com/pub/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.unicamp.br/pub6/netscape/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.mox.uniandes.edu.co/pub/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.nsu.ru/pub/mirrors/ftp-de.netscape.com/pub/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.curtin.edu.au/pub/internet/netscape/${NETSCAPE_DIST_SUBDIR}/
.endif
DISTFILES=	${BROWSER}-v${BROWSER_V}-us.${NETSCAPE_DIST_TAG}.tar.gz

MASTERDIR=	${.CURDIR}/../netscape4-communicator
WRKSRC=		${WRKDIR}/${BROWSER}-v${BROWSER_V}.${NETSCAPE_DIST_TAG}
ONLY_FOR_ARCHS?=	i386 alpha

.if ${ARCH} == "alpha" && !defined(BROWSER)
PLIST=		${PKGDIR}/pkg-plist.alpha
.endif

.if ${ARCH} == "alpha"
NETSCAPE_DIST_ARCH=	supported/dec_unix40
NETSCAPE_DIST_TAG=	alpha-dec-osf4.0
.endif

.if defined(BROWSER) && ${BROWSER} == "navigator"
NETSCAPE_DIST_GRADE=	navigator_standalone
.endif

NETSCAPE_DIST_ARCH?=	unsupported/freebsd # | supported/dec_unix40 | supported/linux22 | unsupported/bsdi21
NETSCAPE_DIST_GRADE?=	complete_install # | navigator_standalone
NETSCAPE_DIST_SUBDIR?=	communicator/english/${BROWSER_VER}/unix/${NETSCAPE_DIST_ARCH}/${NETSCAPE_DIST_GRADE}
NETSCAPE_DIST_TAG?=	x86-unknown-freebsd # | x86-unknown-linux2.2 | x86-bsdi-bsd2 | alpha-dec-osf4.0

BROWSER_VER=	${PORTVERSION}
BROWSER_V!=	${ECHO} ${BROWSER_VER} | sed -e 's/\.//'
INFILE_HEAD?=	'Communicator,4.76.0.20001006'
NO_AUTOADMIN=	'Not available'
NO_FORTIFY=	'No need for this version'

.include "${MASTERDIR}/Makefile"

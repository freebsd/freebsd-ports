# New ports collection makefile for: netscape (communicator suite)
# Date created:		24 Feb 1997
# Whom:			thepish
#
# $FreeBSD$
#

PORTNAME?=	netscape-${BROWSER_ARC}
PORTVERSION?=	${BROWSER_VER}

.if !defined(_PREMKINCLUDED)
.include <bsd.port.pre.mk>
.endif

MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/english/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.spin.ad.jp/pub/WWW/netscape/communicator/english/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.sunet.se/pub/www/Netscape/communicator/english/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.hi.is/pub/mirrors/ftp.netscape.com/pub/communicator/english/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://ftp.unicamp.br/pub6/netscape/communicator/english/${NETSCAPE_DIST_SUBDIR}/ \
		ftp://the.ausmac.net/wd2a/security/cryptography/128bit-browsers/Netscape/${NETSCAPE_DIST_SUBDIR}/
DISTFILES=	${BROWSER}-v474-us.${NETSCAPE_DIST_TAG}.tar.gz

MASTERDIR=	${.CURDIR}/../netscape4-communicator
WRKSRC?=	${WRKDIR}/${BROWSER}-v474.${NETSCAPE_DIST_TAG}
ONLY_FOR_ARCHS?=	i386 alpha

.if ${ARCH} == "alpha"
NETSCAPE_DIST_ARCH=	supported/dec_unix40
NETSCAPE_DIST_TAG=	alpha-dec-osf4.0
.endif

.if defined(BROWSER) && ${BROWSER} == 'navigator'
NETSCAPE_DIST_GRADE=	navigator_standalone
.endif

NETSCAPE_DIST_ARCH?=	unsupported/freebsd # | supported/dec_unix40 | supported/linux22 | unsupported/bsdi21
NETSCAPE_DIST_GRADE?=	complete_install # | navigator_standalone
NETSCAPE_DIST_SUBDIR?=	${BROWSER_VER}/unix/${NETSCAPE_DIST_ARCH}/${NETSCAPE_DIST_GRADE}
NETSCAPE_DIST_TAG?=	x86-unknown-freebsd # | x86-unknown-linux2.2 | x86-bsdi-bsd2 | alpha-dec-osf4.0

BROWSER_VER=	4.74
INFILE_HEAD?=	'Communicator,4.74.0.20000707'
NO_AUTOADMIN=	'Not available'
NO_FORTIFY=	'No need for 4.74'

.include "${MASTERDIR}/Makefile"

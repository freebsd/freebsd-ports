# New ports collection makefile for:	cvsup-devel
# Date created:		28 April 2001
# Whom:			jdp
#
# $FreeBSD$
#

PORTVERSION=	16.1c
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp3.freebsd.org/pub/FreeBSD/development/CVSup/snapshots/ \
		ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/snapshots/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/development/CVSup/snapshots/
DISTNAME=	cvsup-snap-${PORTVERSION}

MASTERDIR=	${.CURDIR}/../cvsup
FILESDIR=	${.CURDIR}/files
MD5_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PKGDIR=		${.CURDIR}

post-install:
	@${MKDIR} ${PREFIX}/share/cvsup
	@${INSTALL_DATA} ${WRKSRC}/License ${PREFIX}/share/cvsup/License

.include "${MASTERDIR}/Makefile"

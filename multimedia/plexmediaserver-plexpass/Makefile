# Created by: KalleDK <plexmaintainer@k-moeller.dk>

PORTVERSION=	1.24.1.4931
DISTVERSIONSUFFIX=1a38e63c6
PORTREVISION=	0
MASTER_SITES=	https://downloads.plex.tv/plex-media-server-new/${DISTVERSION}-${DISTVERSIONSUFFIX}/freebsd/
PKGNAMESUFFIX=	-plexpass
DISTNAME=	PlexMediaServer-${DISTVERSION}-${DISTVERSIONSUFFIX}-FreeBSD-${ARCH}

MAINTAINER=	feld@FreeBSD.org

USE_RC_SUBR=	${PORTNAME}_plexpass

MASTERDIR=${.CURDIR}/../plexmediaserver

DISTINFO_FILE=	${.CURDIR}/distinfo
FILESDIR=	${.CURDIR}/files
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

SUB_LIST=	PORTNAME=${PORTNAME}_plexpass DATADIR=${DATADIR} USERS=${USERS} GROUPS=${GROUPS}

.include "${MASTERDIR}/Makefile"

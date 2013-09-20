# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exquisite
PORTVERSION=	0.2004081000
MASTER_SITES=	http://myspeedworks.com/~guppetto/downloads/
DISTNAME=	Exquisite

COMMENT=	KDE Exquisite iconset

BROKEN=	checksum mismatch

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
PLIST_FILE_PATTERN_EXTRA=	-v "^\./(buildset|[a-z]+.list)"

NO_STAGE=	yes
.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"

DISTVERSION=	0.21-74 # git rev-list --count v0.21..
DISTVERSIONSUFFIX=	-g52374bc
PKGNAMESUFFIX=	-devel

MASTERDIR=	${.CURDIR}/../celluloid
DISTINFO_FILE=	${.CURDIR}/distinfo

USE_GNOME=	gtk40
PLIST_FILES=	${id ie ko nb_NO te ur:L:C,.*,share/locale/&/LC_MESSAGES/${PORTNAME}.mo,}

.include "${MASTERDIR}/Makefile"

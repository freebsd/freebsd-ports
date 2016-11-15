# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IcOsX
PORTVERSION=	0.7
MASTER_SITES=	http://physics.ramapo.edu/downloads/ \
		http://easylinuxguide.com/downloads/kde-iconthemes/ \
		ftp://ftp.itsinternet.net/pub/FreeBSD/ports/distfiles/KDE/ \
		ftp://relay1.tomsk.gov.ru/pub/FreeBSD/ports/distfiles/KDE/

COMMENT=	KDE IcOsX iconset

BROKEN=		does not fetch

WRKSRC=		${WRKDIR}/${PORTNAME}
PORT_SHAREDIR?=	"${PORTNAME}-${PORTVERSION}"

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"

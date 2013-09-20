# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gartoon
PORTVERSION=	1.3
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://ns.ael.ru/ports/distfiles/KDE/
MASTER_SITE_SUBDIR=	fluffy
PKGNAMESUFFIX=	-blue-svg
DISTNAME=	ICONS-Gartoon.Blue-SVG-v${PORTVERSION}

COMMENT=	KDE Gartoon Blue SVG iconset

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/Gartoon.Blue
PORT_SHAREDIR?=	"${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}"

NO_STAGE=	yes
.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"

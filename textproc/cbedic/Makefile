# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cbedic
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/kbedic/CBE%20Dictionary/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English-to-Bulgarian and Bulgarian-to-English dictionary

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2

RUN_DEPENDS=	${DICT_DIR}/${DICT_CHECK}:textproc/bedic-data

DICT_CHECK?=	buleng.dat
DICT_DIR?=	${LOCALBASE}/share

USES=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--datadir=${DICT_DIR}

PLIST_FILES=	bin/cbedic

.include <bsd.port.mk>

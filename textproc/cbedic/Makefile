# New ports collection makefile for:	cbedic
# Date created:			15 April 2002
# Whom:				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cbedic
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=kbedic

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An English-to-Bulgarian and Bulgarian-to-English dictionary

RUN_DEPENDS=	${DICT_DIR}/${DICT_CHECK}:${PORTSDIR}/textproc/bedic-data

DICT_CHECK?=	buleng.dat
DICT_DIR?=	${LOCALBASE}/share

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--datadir=${DICT_DIR}

.include <bsd.port.mk>

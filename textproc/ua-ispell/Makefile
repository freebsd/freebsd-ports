# New ports collection makefile for:    ukr-ispell
# Date created:         5 Dec 2000
# Whom:                 mi
#
# $FreeBSD$
#

PORTNAME=	ispell
PORTVERSION=	0.0.2b
CATEGORIES=     textproc ukrainian
MASTER_SITES=   http://virtual-estates.net/port-stuff/ \
		http://www.brama.com/compute/unix/ \
		ftp://cad.ntu-kpi.kiev.ua/soft/lingvist/UkrIspell/
PKGNAMEPREFIX=	ua-
DISTNAME=	ua-ispell.${PORTVERSION}

MAINTAINER=     mi@aldan.algebra.com

BUILD_DEPENDS=  buildhash:${PORTSDIR}/textproc/ispell

ALL_TARGET=	all,koi

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} ukrainian.hash ukrainian.aff ${PREFIX}/share/ispell

.include <bsd.port.mk>

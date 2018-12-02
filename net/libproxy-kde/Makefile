# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net devel
PKGNAMESUFFIX=	-${LIBPROXY_SLAVE}

COMMENT=	KDE plug-in for libproxy

DEPRECATED=	KDE4 is end-of-life
EXPIRATION_DATE=2018-12-31

USES=		kde:4
USE_KDE=	runtime

LIBPROXY_SLAVE=	kde
MASTERDIR=	${.CURDIR}/../libproxy

.include "${MASTERDIR}/Makefile"

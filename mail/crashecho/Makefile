# Ports collection makefile for:	crashecho
# Date created:		15 November 2002
# Whom:			CyrilM <cyrilm@tower.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	crashecho
PORTVERSION=	0.2.14
CATEGORIES=	mail
MASTER_SITES=	http://hell.binec.ru/crashecho/

DEPRECATED=	"sourceforge site \(crashecho\) up but barren"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An FTN JAM and *.MSG tosser

LIB_DEPENDS=	jam.2:${PORTSDIR}/mail/jamlib

USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	crashecho.1 \
	crashexport.1 \
	crashmaint.1 \
	crashstats.1 \
	crashwrite.1
MAN5=	crashecho.conf.5

post-install:
	${MKDIR} ${PREFIX}/etc/ftn
	${INSTALL_DATA} ${WRKSRC}/doc/crashecho.conf ${PREFIX}/etc/ftn/crashecho.conf.sample
.include <bsd.port.mk>

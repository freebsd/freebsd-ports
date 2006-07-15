# ports collection makefile for:	SmsSend
# Date created:				1st January 2001
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	smssend
PORTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://zekiller.skytech.org/fichiers/smssend/

MAINTAINER=	mico@bsd.hu
COMMENT=	A tool to send a SMS to any GSM

BROKEN=		fails to compile

LIB_DEPENDS=	skyutils-2.9.9:${PORTSDIR}/misc/skyutils

MAN1=	smssend.1 smssend.scripting.1 email2smssend.1

MANLANG=	"" fr

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/smssend

.include <bsd.port.mk>

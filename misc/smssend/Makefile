# ports collection makefile for:	SmsSend
# Date created:				1st January 2001
# Whom:					Miklos Niedermayer <mico@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	smssend
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://zekiller.skytech.org/fichiers/smssend/

MAINTAINER=	mico@bsd.hu
COMMENT=	A tool to send a SMS to any GSM

MAN1=	smssend.1 smssend.scripting.1 email2smssend.1

MANLANG=	"" fr

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/smssend

.include <bsd.port.mk>

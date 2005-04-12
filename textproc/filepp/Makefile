# ex:ts=8
# New ports collection makefile for:	filepp
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	filepp
PORTVERSION=	1.7.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.cabaret.demon.co.uk/filepp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A generic file preprocessor

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
NO_BUILD=	yes

MAN1=	filepp.1

.include <bsd.port.mk>

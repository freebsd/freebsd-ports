# New ports collection makefile for:	hello
# Date created:				Fri Jul 23, 1999
# Whom:					shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	hello
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	hello

MAINTAINER=	shipley@dis.org
COMMENT=	A utility for saying hello to the world and reading email

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_PERL5_BUILD=	YES
GNU_CONFIGURE=	YES
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=		hello.1

.include <bsd.port.mk>

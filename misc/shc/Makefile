# ex:ts=8
# New ports collection makefile for:	shc
# Date created:		Feb 14, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shc
PORTVERSION=	3.3
CATEGORIES=	misc
MASTER_SITES=	ftp://asterix.fi.upm.es/pub/facultad/departamentos/datsi/frosal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A shell script "encoder"

IGNORE=		"Produces broken binaries"

USE_REINPLACE=	yes
ALL_TARGET=	shc

MAN1=	shc.1

post-patch:
	@${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS},g ; \
		s,/usr/local,${PREFIX},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>

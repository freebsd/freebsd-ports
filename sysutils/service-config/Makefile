# New ports collection makefile for:	service-config
# Date created:				2 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	service-config
PORTVERSION=	0.51
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/service-config/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Utility to create and configure svscan service directories

RUN_DEPENDS=	supervise:${PORTSDIR}/sysutils/daemontools

ALL_TARGET=	it
INSTALL_TARGET=	setup check
USE_PERL5_BUILD=yes

NO_PACKAGE=	A possibly inherited DJB-style license would prohibit \
		distribution of modified binary packages

post-patch:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${CFLAGS} ${STRIP}" > ${WRKSRC}/conf-ld
	@${PERL} -pi -e 's!/usr/local!${PREFIX}!g' ${WRKSRC}/conf-home

.include <bsd.port.mk>

# New ports collection makefile for:	powerman
# Date created:		29 March 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	powerman
PORTVERSION=	1.0.20
CATEGORIES=	sysutils parallel
MASTER_SITES=	ftp://ftp.llnl.gov/pub/linux/powerman/
EXTRACT_SUFX=	.tgz

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	PowerMan is a tool for doing remote power control

USE_BISON=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
USE_RC_SUBR=	yes
USE_REINPLACE=	yes

MAKE_ENV+=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		powerman.1
MAN5=		powerman.conf.5
MAN7=		powerman-devices.7
MAN8=		powermand.8

post-patch:
.for file in ${MAN1} ${MAN5} powermand.1
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:" "${WRKSRC}/man/${file}"
.endfor
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:" \
		"${WRKSRC}/src/powerman.h"
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%RC_SUBR%%:${RC_SUBR}:" \
		"${WRKSRC}/scripts/powerman.init"

.include <bsd.port.mk>

# New ports collection makefile for:	bpm
# Date created:				23 July 2004
# Whom:					sethk
#
# $FreeBSD$
#

PORTNAME=	bpm
PORTVERSION=	0.4.1b
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.meowfishies.com/code/bpm/
EXTRACT_SUFX=	.tgz
MAINTAINER=	sethk@meowfishies.com
COMMENT=	A graphical BSD ports collection manager

RUN_DEPENDS=	portupgrade:${PORTSDIR}/sysutils/portupgrade

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes

MAKE_ENV+=	OSTYPE="${OPSYS}"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s|-lintl|-lintl -L${LOCALBASE}/lib|g"

.include <bsd.port.mk>

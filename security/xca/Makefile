# New ports collection makefile for: xca
# Date created:		2002-12-23
# Whom:			Valentin Zahariev <curly@e-card.bg>
#
# $FreeBSD$
#

PORTNAME=	xca
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	curly@e-card.bg
COMMENT=	Graphical certification authority

LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
USE_QT_VER=	3

post-patch:
	@${REINPLACE_CMD} -E -e 's,(if[\ \t]+test[\ \t]+.+)[\ \t]+==,\1 =,' \
		${WRKDIR}/${PKGNAME}/configure

.include <bsd.port.mk>

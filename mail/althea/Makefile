# New ports collection makefile for:	Althea
# Date created:		Feb 26, 2001
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	althea
PORTVERSION=	0.5.7
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_GTK=	yes
USE_OPENSSL=	yes
MAKE_ENV=	MKDIR="${MKDIR}"
MAKEFILE=	${FILESDIR}/Makefile.bsd

post-patch:
.for file in Documentation/help.html load_config.h save_config.h
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>

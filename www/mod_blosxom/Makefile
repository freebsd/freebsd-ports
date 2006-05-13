# New ports collection makefile for:	mod_blosxom
# Date created:				6 April 2003
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mod_blosxom
PORTVERSION=	0.05
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-blosxom

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Apache module to build the extremely lightweight Weblog environment

USE_APACHE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,^APXS=.*,APXS=${APXS},' ${WRKSRC}/Makefile

.include <bsd.port.mk>

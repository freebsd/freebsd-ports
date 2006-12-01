# New ports collection makefile for: wsmake
# Date created:        31 May, 2002
# Whom:                Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	wsmake
PORTVERSION=	0.6.4
CATEGORIES=	www
MASTER_SITES=	SFE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for production and maintenance of web sites

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wsmake

post-patch:
	@${REINPLACE_CMD} -e 's,void\*,char\*,g' ${WRKSRC}/libwsmake/wsUtil.cpp

.include <bsd.port.mk>

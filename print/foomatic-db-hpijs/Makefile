# New ports collection makefile for:	foomatic-db-hpijs
# Date created:		2005-09-17
# Whom:			Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	foomatic-db-hpijs
PORTVERSION=	1.4
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	lofi@FreeBSD.org
COMMENT=	Foomatic data for the HPIJS printer drivers

BUILD_DEPENDS=	${LOCALBASE}/share/foomatic/db/oldprinterids:${PORTSDIR}/print/foomatic-db
RUN_DEPENDS=	${LOCALBASE}/share/foomatic/db/oldprinterids:${PORTSDIR}/print/foomatic-db

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
			 -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure

.include <bsd.port.mk>

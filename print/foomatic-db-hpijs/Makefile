# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foomatic-db-hpijs
PORTVERSION=	1.4
DISTVERSIONSUFFIX=	-1
CATEGORIES=	print
MASTER_SITES=	LOCAL/lofi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Foomatic data for the HPIJS printer drivers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/foomatic/db/oldprinterids:print/foomatic-db
RUN_DEPENDS=	${LOCALBASE}/share/foomatic/db/oldprinterids:print/foomatic-db

GNU_CONFIGURE=	yes
USES=		gmake perl5
USE_PERL5=	build

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
			 -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure

.include <bsd.port.mk>

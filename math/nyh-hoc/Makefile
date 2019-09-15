# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hoc
PORTVERSION=	9.2
CATEGORIES=	math
MASTER_SITES=	http://nadav.harel.org.il/homepage/hoc/
PKGNAMEPREFIX=	nyh-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High Order Calculator

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

MAKE_JOBS_UNSAFE= yes

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hoc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

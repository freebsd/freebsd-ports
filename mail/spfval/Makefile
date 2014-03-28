# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	spfval
PORTVERSION=	0.0.1
CATEGORIES=	mail
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	SPF validator

USES=		tar:bzip2
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/spfval

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/spfval ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

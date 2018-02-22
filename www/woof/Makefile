# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	woof
DISTVERSION=	2012-05-31
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.home.unix-ag.org/simon/
EXTRACT_SUFX=	.py
EXTRACT_ONLY=	# empty

MAINTAINER=	dereckson@gmail.com
COMMENT=	Web Offer One File, an ad-hoc single file webserver

LICENSE=	GPLv2+

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	${DISTFILES}
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/woof

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTFILES} ${STAGEDIR}${PREFIX}/bin/woof

.include <bsd.port.mk>

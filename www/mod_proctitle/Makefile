# Created by: stas
# $FreeBSD$

PORTNAME=	mod_proctitle
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	Set httpd process titles to reflect currently processed request

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		apache autoreconf libtool

USE_GITHUB=	yes
GH_ACCOUNT=	MirLach

CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/apr-1

PLIST_FILES=	${APACHEMODDIR}/${PORTNAME}.so

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/mod_proctitle.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.mk>

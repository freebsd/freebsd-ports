# Created by: stas
# $FreeBSD$

PORTNAME=	mod_proctitle
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.springdaemons.com/soft/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Set httpd process titles to reflect currently processed request

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		apache:2.2+ tar:bzip2

CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/apr-1

PLIST_FILES=	${APACHEMODDIR}/${PORTNAME}.so

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/mod_proctitle.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.mk>

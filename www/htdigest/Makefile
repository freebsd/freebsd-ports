PORTNAME=	htdigest
PORTVERSION=	2.4.56
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	https://archive.apache.org/dist/httpd/
DISTNAME=	httpd-${PORTVERSION}
DIST_SUBDIR=	apache24

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Utility from the Apache distribution for creating htdigest files
WWW=		https://httpd.apache.org/

LICENSE=	APACHE20

LIB_DEPENDS=	libaprutil-1.so:devel/apr1 \
		libexpat.so:textproc/expat2

USES=		iconv

PLIST_FILES=	bin/apache-${PORTNAME} share/man/man1/apache-${PORTNAME}.1.gz

GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/support

# Don't actually need pcre, so hack around
post-patch:
	${REINPLACE_CMD} -e '/^[[:space:]]*as_fn_error[^"]*"[^"]*pcre/d' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/support/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/apache-htdigest
	${INSTALL_MAN} ${WRKSRC}/docs/man/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/apache-htdigest.1

.include <bsd.port.mk>

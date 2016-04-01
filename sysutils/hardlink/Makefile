# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	hardlink
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	http://jak-linux.org/projects/hardlink/ \
		DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Replace file copies using hardlinks

LICENSE=	MIT

USES=		pkgconfig tar:xz

PLIST_FILES=	bin/hardlink \
		man/man1/hardlink.1.gz
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

PORTSCOUT=	limit:(?<!~rc[0-9])$$

OPTIONS_DEFINE=	PCRE
OPTIONS_DEFAULT=PCRE

PCRE_LIB_DEPENDS=	libpcreposix.so:devel/pcre
PCRE_MAKE_ENV_OFF=	ENABLE=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hardlink ${STAGEDIR}${PREFIX}/bin/hardlink
	${INSTALL_MAN} ${WRKSRC}/hardlink.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/hardlink.1

.include <bsd.port.mk>

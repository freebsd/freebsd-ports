# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	hardlink
PORTVERSION=	0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://jak-linux.org/projects/hardlink/ \
		DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Replace file copies using hardlinks

LICENSE=	MIT

USES=		pkgconfig

PLIST_FILES=	bin/hardlink \
		man/man1/hardlink.1.gz
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

OPTIONS_DEFINE=	PCRE

OPTIONS_DEFAULT=PCRE

PORTSCOUT=	limit:(?<!~rc[0-9])$$

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	libpcreposix.so:${PORTSDIR}/devel/pcre
.else
MAKE_ENV+=	ENABLE=
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hardlink ${STAGEDIR}${PREFIX}/bin/hardlink
	${INSTALL_MAN} ${WRKSRC}/hardlink.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/hardlink.1

.include <bsd.port.mk>

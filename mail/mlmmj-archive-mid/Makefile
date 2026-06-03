PORTNAME=	mlmmj-archive-mid
DISTVERSION=	0.3
CATEGORIES=	mail www
MASTER_SITES=	https://fossil.nours.eu/${PORTNAME}/tarball/?r=${DISTVERSION}&name=./

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	CGI helping mapping a message id to an archived mail
WWW=		https://fossil.nours.eu/mlmmj-archive-mid

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libkcgi.so:www/kcgi

USES=		sqlite:3 uidfix pkgconfig

MAKE_ARGS=	MAN= LOCALBASE=${LOCALBASE}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM}  ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

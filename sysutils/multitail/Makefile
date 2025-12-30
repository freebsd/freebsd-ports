PORTNAME=	multitail
PORTVERSION=	7.1.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/folkertvanheusden/multitail/archive/refs/tags/
DISTNAME=	${PORTVERSION}

MAINTAINER=	laszlo@karolyi.hu
COMMENT=	Tail multiple files on console with ncurses
WWW=		https://www.vanheusden.com/multitail/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgnuregex.so:devel/libgnuregex

USES=		cmake ncurses pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/multitail etc/multitail.conf.sample \
		share/man/man1/multitail.1.gz
PORTDOCS=	README.md LICENSE

OPTIONS_DEFINE= DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/multitail ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/multitail.conf ${STAGEDIR}${PREFIX}/etc/multitail.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

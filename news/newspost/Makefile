# Created by: Michael L. Hostbaek <mich@freebsdcluster.org>
# $FreeBSD$

PORTNAME=	newspost
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://newspost.unixcab.org/download/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Full-featured Usenet binary autoposter

LICENSE=	GPLv2

ALL_TARGET=	main
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

# Change "cd foo; $(MAKE)" into "$(MAKE) -C foo" to unbreak parallel builds
post-patch:
	@${REINPLACE_CMD} -E 's|cd(.+) ; (\$$\(MAKE\))|\2 -C\1|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

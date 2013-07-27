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

MAN1=		${PORTNAME}.1
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# Change "cd foo; $(MAKE)" into "$(MAKE) -C foo" to unbreak parallel builds
post-patch:
	@${REINPLACE_CMD} -E 's|cd(.+) ; (\$$\(MAKE\))|\2 -C\1|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${MAN1} ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

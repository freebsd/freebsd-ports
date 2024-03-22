PORTNAME=	ltrace
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/sbz \
		http://www.zonov.org/${PORTNAME}/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Track runtime library calls in dynamically linked programs
WWW=		https://ltrace.org/

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-werror
CONFIGURE_ARGS+=	--without-libunwind # fix build: configure is looking for and finds libunwind.h, but the C code later doesn't find libunwind-ptrace.h and breaks
ONLY_FOR_ARCHS=	amd64

OPTIONS_DEFINE=	DOCS

PORTDOCS=	BUGS COPYING ChangeLog README TODO

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

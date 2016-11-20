# Created by: Simon Riget <freebsd@paragi.dk>
# $FreeBSD$

PORTNAME=	kissdx
PORTVERSION=	0.13.10a
PORTREVISION=	14
CATEGORIES=	multimedia net
MASTER_SITES=	http://paragi.dk/kiss/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia streaming server for KiSS/Linksys player

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgd.so:graphics/gd \
		libdvdread.so:multimedia/libdvdread

BROKEN_powerpc64=	Does not build

USES=		compiler:nestedfct dos2unix iconv jpeg
MAKE_ENV=	FreeBSD=defined

USE_RC_SUBR=	kissdx
SUB_FILES=	pkg-message

PORTDOCS=	README
PLIST_FILES=	etc/kissdx.conf man/man1/kissdx.1.gz  \
		sbin/kissd-posttrigger sbin/kissd-pretrigger sbin/kissdx

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|Linux|Unix| ; \
		 s|/etc/|${PREFIX}&|' ${WRKSRC}/kissdx.1
	@${REINPLACE_CMD} -e \
		's|/etc/|${PREFIX}&|' ${WRKSRC}/config.c
# Fix parallel (-jX) builds: sanitize dependencies
	@${REINPLACE_CMD} -e \
		's|-liconv|${ICONV_LIB}| ; \
		 s|^\.o :|${PORTNAME}: $$(OBJS)| ; \
		 /^all:/s| $$(OBJS)||' ${WRKSRC}/Makefile

pre-build:
	@${RM} ${WRKSRC}/kissdx.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kissdx ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/kissd-pretrigger ${WRKSRC}/kissd-posttrigger ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/kissdx.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/kissdx.conf ${STAGEDIR}${PREFIX}/etc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

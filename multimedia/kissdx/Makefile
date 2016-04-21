# Created by: Simon Riget <freebsd@paragi.dk>
# $FreeBSD$

PORTNAME=	kissdx
PORTVERSION=	0.13.10a
PORTREVISION=	11
CATEGORIES=	multimedia net
MASTER_SITES=	http://paragi.dk/kiss/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia streaming server for KiSS/Linksys player

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libgd.so:graphics/gd \
		libdvdread.so:multimedia/libdvdread

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
	@${RM} -f ${WRKSRC}/kissdx.o

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} kissdx \
		${STAGEDIR}${PREFIX}/sbin)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} kissd-pretrigger kissd-posttrigger \
		${STAGEDIR}${PREFIX}/sbin)
	(cd ${WRKSRC} && ${INSTALL_MAN} kissdx.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC} && ${INSTALL_DATA} kissdx.conf \
		${STAGEDIR}${PREFIX}/etc)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

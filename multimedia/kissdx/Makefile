# Created by: Simon Riget <freebsd@paragi.dk>
# $FreeBSD$

PORTNAME=	kissdx
PORTVERSION=	0.13.10a
PORTREVISION=	8
CATEGORIES=	multimedia net
MASTER_SITES=	http://paragi.dk/kiss/

MAINTAINER=	freebsd@paragi.dk
COMMENT=	Multimedia streaming server for KiSS/Linksys player

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libdvdread.so:${PORTSDIR}/multimedia/libdvdread

USES=		iconv
USE_DOS2UNIX=	yes
MAKE_ENV=	FreeBSD=defined

MAN1=		kissdx.1
USE_RC_SUBR=	kissdx
SUB_FILES=	pkg-message

PLIST_FILES=	etc/kissdx.conf sbin/kissdx sbin/kissd-pretrigger \
		sbin/kissd-posttrigger
PORTDOCS=	README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|Linux|Unix| ; s|/etc/|${PREFIX}&|' \
		${WRKSRC}/kissdx.1
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|' ${WRKSRC}/config.c
	@${RM} ${WRKSRC}/kissdx.o
# Fix parallel (-jX) builds: sanitize dependencies
	@${REINPLACE_CMD} -e 's|^\.o :|kissdx: $$(OBJS)| ; \
		/^all:/s| $$(OBJS)||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kissdx ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/kissd-pretrigger ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/kissd-posttrigger ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/kissdx.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/kissdx.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>

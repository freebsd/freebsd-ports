PORTNAME=	open
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.hs-niederrhein.de/pub/linux/src/ \
		ftp://ftp.uni-bremen.de/pub/mirrors/sunsite/utils/console/ \
		LOCAL/fjoe

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open opens a new vt and runs a command on it

ALL_TARGET=	open
PLIST_FILES=	bin/open share/man/man1/open.1.gz
OPTIONS_DEFINE=	SETUID
SETUID_DESC=	Install setuid open binary
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/open ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/open.1 ${STAGEDIR}${PREFIX}/share/man/man1
.if ${PORT_OPTIONS:MSETUID}
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/open
.else
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
.endif

.include <bsd.port.mk>

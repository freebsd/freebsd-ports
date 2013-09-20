# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	open
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.hs-niederrhein.de/pub/linux/src/ \
		ftp://ftp.uni-bremen.de/pub/mirrors/sunsite/utils/console/ \
		${MASTER_SITE_LOCAL:S^$^fjoe/^}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Open opens a new vt and runs a command on it

ALL_TARGET=	open
MAN1=		open.1
PLIST_FILES=	bin/open
OPTIONS_DEFINE=	SETUID
SETUID_DESC=	Install setuid open binary
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/open ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/open.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MSETUID}
	${CHMOD} u+s ${PREFIX}/bin/open
.else
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>

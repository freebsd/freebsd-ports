# New ports collection makefile for:	kissdx
# Date created:				20. November 2007
# Whom:					Simon I. Rigét
#
# $FreeBSD$
#

PORTNAME=	kissdx
PORTVERSION=	0.13.10a
PORTREVISION=	2
CATEGORIES=	multimedia net
MASTER_SITES=	http://paragi.dk/kiss/

MAINTAINER=	freebsd@paragi.dk
COMMENT=	A multimedia streaming server for KiSS/Linksys player

# Dependencies of other packeges
LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		jpeg:${PORTSDIR}/graphics/jpeg \
		dvdread:${PORTSDIR}/multimedia/libdvdread

USE_ICONV=	yes

# Man pages
MAN1=		kissdx.1

# RC start and stop service
USE_RC_SUBR=	kissdx

# set enviroment variables for port makefile
MAKE_ENV=	FreeBSD=defined LDFLAGS="${LDFLAGS}"

# Convert CR/LF to LF in source files
USE_DOS2UNIX=	yes

SUB_FILES=	pkg-message

# Remove files at uninstall (like pkg-plist)
PLIST_FILES=	etc/kissdx.conf sbin/kissdx sbin/kissd-pretrigger sbin/kissd-posttrigger

post-patch:
	@${REINPLACE_CMD} -e 's|Linux|Unix|g ; s|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/kissdx.1
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/config.c
	@${RM} ${WRKSRC}/kissdx.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kissdx ${PREFIX}/sbin/kissdx
	${INSTALL_SCRIPT} ${WRKSRC}/kissd-pretrigger ${PREFIX}/sbin/kissd-pretrigger
	${INSTALL_SCRIPT} ${WRKSRC}/kissd-posttrigger ${PREFIX}/sbin/kissd-posttrigger
	${INSTALL_DATA} ${WRKSRC}/kissdx.conf ${PREFIX}/etc/kissdx.conf
	${INSTALL_MAN} ${WRKSRC}/kissdx.1 ${MANPREFIX}/man/man1/kissdx.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

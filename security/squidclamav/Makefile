# Created by: Laurent LEVIER <llevier@argosnet.com>
# $FreeBSD$

PORTNAME=	squidclamav
PORTVERSION=	5.7
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	llevier@argosnet.com
COMMENT=	Squid interface to ClamAV

DEPRECATED=	Obsolete and broken with clang, use www/squidclamav instead
EXPIRATION_DATE=2013-12-02

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
NO_LATEST_LINK=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.dist
MAN1=		${PORTNAME}.1

NO_STAGE=	yes
post-configure:
	@${REINPLACE_CMD} -E 's|^(LDFLAGS = ).*|\1-L${LOCALBASE}/lib|' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/etc/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.dist
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1/${PORTNAME}.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

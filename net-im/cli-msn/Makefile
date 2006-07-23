# New ports collection makefile for:	climsn
# Date created:		2006-03-31
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	msn
PORTVERSION=	2.3
CATEGORIES=	net-im
MASTER_SITES=	http://mor-pah.net/code/
PKGNAMEPREFIX=	cli-
DISTNAME=	CLI-MSN-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Command line msn messenger

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_LIBS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

SUB_FILES=	pkg-message
PLIST_FILES=	bin/cli-msn \
		share/${PKGNAMEPREFIX}${PORTNAME}/msn.conf \
		share/${PKGNAMEPREFIX}${PORTNAME}/curl-ca-bundle.crt
PLIST_DIRS=	share/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msn ${PREFIX}/bin/cli-msn

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/msn.conf ${WRKSRC}/curl-ca-bundle.crt ${DATADIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

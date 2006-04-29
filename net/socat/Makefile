# ex:ts=8
# Ports collection makefile for:	socat
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	socat
PORTVERSION=	1.4.3.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	freebsd-ports@rikrose.net
COMMENT=	Multipurpose relay and more

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:R}
USE_BZIP2=	yes

GNU_CONFIGURE=	yes

MAN1=		socat.1

.if !defined(NOPORTDOCS)
PORTDOCS=	EXAMPLES README SECURITY FAQ
.endif

PLIST_FILES=	bin/filan bin/procan bin/socat

OPTIONS=	SSL "OpenSSL support" on

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

# ex:ts=8
# Ports collection makefile for:	socat
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	socat
PORTVERSION=	1.4.0.3
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	freebsd-ports@rikrose.net
COMMENT=	Multipurpose relay and more

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:R}
USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	CCOPT="${CFLAGS}"

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=	yes
.endif

MAN1=		socat.1
PORTDOCS=	EXAMPLES README SECURITY FAQ
PLIST_FILES=	bin/filan bin/procan bin/socat

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

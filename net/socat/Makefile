# ex:ts=8
# Ports collection makefile for:	socat
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	socat
PORTVERSION=	1.3.2.2
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multipurpose relay and more

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R:R}
USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	CCOPT="${CFLAGS}"

MAN1=		socat.1
DOCS=		EXAMPLES README SECURITY

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	socat
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	socat
PORTVERSION=	1.3.2.1
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

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	tvmet
# Date created:			Jul 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tvmet
PORTVERSION=	0.5.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Tiny Vector and Matrix template library

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	tvmet-config.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in h cc css doc png
	${INSTALL_DATA} ${WRKSRC}/doc/*.${ext} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for ext in cc
	${INSTALL_DATA} ${WRKSRC}/examples/*.${ext} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>

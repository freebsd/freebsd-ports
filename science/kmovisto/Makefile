# ex:ts=8
# Ports collection Makefile for:	kmovisto
# Date created:			Oct 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kmovisto
PORTVERSION=	0.7.0
CATEGORIES=	science
MASTER_SITES=	http://mitglied.lycos.de/pageofmh/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A real 3-D molecule viewer

USE_QT_VER=	3
USE_GL=		yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|-pedantic||g ; \
		 s|-fno-exceptions|-fexceptions|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/kmovisto/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kmovisto/kmovisto ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/kmovisto/docs/en/*.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/kmovisto/docs/en/images/*.jpg ${DOCSDIR}/images
.endif

.include <bsd.port.mk>

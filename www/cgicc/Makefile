# ex:ts=8
# New ports collection makefile for:	cgi++
# Date created:			Mar 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgicc
PORTVERSION=	3.2.1
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| install-data-local||g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>

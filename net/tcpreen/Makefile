# New ports collection makefile for:	tcpreen
# Date created:				09.08.2002
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	tcpreen
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	A simple TCP session re-engineering tool

USE_BZIP2=	yes
USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAN1=		tcpreen.1

DOC_FILES=	AUTHORS NEWS README THANKS TODO

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

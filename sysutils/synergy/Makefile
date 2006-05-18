# New ports collection makefile for:	synergy
# Date created:		26 March 2003
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	synergy
PORTVERSION= 	1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}2

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}	
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/synergy
	${INSTALL_DATA} ${WRKSRC}/examples/synergy.conf ${PREFIX}/share/examples/synergy

.include <bsd.port.mk>

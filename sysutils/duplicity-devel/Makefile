# New ports collection makefile for:	duplicity
# Date created:				Wed Jun 11 19:53:46 CEST 2003
# Whom:					Gerhard Häring <gh@ghaering.de>
#
# $FreeBSD$
#

PORTNAME=	duplicity
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Untrusted backup using rsync algorithm

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync
RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		duplicity.1 rdiffdir.1

DOCFILES=	CHANGELOG COPYING README

post-install:
	${INSTALL_MAN} ${WRKSRC}/duplicity.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/rdiffdir.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

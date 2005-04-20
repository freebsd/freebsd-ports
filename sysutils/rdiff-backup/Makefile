# New ports collection makefile for:	rdiff-backup
# Date created:		Wed Jun 11 19:53:46 CEST 2003
# Whom:			Gerhard Häring <gh@ghaering.de>
#
# $FreeBSD$
#

PORTNAME=	rdiff-backup
PORTVERSION=	0.12.8
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	steve@ion.lu
COMMENT=	Local/remote mirroring+incremental backup

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		rdiff-backup.1

DOCFILES=	CHANGELOG README COPYING FAQ.html
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

post-install:
	${INSTALL_MAN} ${WRKSRC}/rdiff-backup.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>

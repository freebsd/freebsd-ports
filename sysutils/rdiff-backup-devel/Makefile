# New ports collection makefile for:	rdiff-backup
# Date created:		Fri Jun 10 23:30:39 CEST 2005
# Whom:			Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$
#

PORTNAME=	rdiff-backup-devel
PORTVERSION=	0.13.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nongnu.org/rdiff-backup/
DISTNAME=	rdiff-backup-${PORTVERSION}

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Local/remote mirroring+incremental backup

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync

CONFLICTS=	rdiff-backup-[0-9]*

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

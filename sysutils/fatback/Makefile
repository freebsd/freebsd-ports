# New ports collection makefile for:	fatback
# Date created:				18 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	fatback
DISTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Recover deleted files from FAT filesystems

GNU_CONFIGURE=	yes

MAN1=		fatback.1
INFO=		fatback-manual

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/fatback-manual.info ${PREFIX}/${INFO_PATH}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in fatback-manual.texi texinfo.tex ChangeLog AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	unroff
# Date created:		18 Feb 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	unroff
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www-rn.informatik.uni-bremen.de/software/unroff/%SUBDIR%/
MASTER_SITE_SUBDIR=	dist
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
DIST_SUBDIR=	unroff

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	contrib
PATCHFILES=	me-misc-patch.gz misc-patch-2.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A programmable troff translator with backend for HTML

LIB_DEPENDS=	elk.0:${PORTSDIR}/lang/elk

BUILD_WRKSRC=	${WRKSRC}/src

MAN1=		unroff.1 unroff-html.1 unroff-html-man.1 \
		unroff-html-me.1 unroff-html-ms.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/unroff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${PREFIX}/man/man1
	@${MKDIR} ${DATADIR}/misc
.for i in doc/tmac.hyper misc/sample.unroff
	${INSTALL_DATA} ${WRKSRC}/${i} ${DATADIR}/misc
.endfor
	${TAR} -C ${WRKSRC} -cf - scm | \
		${TAR} -C ${DATADIR} --unlink -xf -
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.ms ${DOCSDIR}
.endif

.include <bsd.port.mk>

# ports collection makefile for:	xmbmon
# Date created:	2001/08/30
# Whom:		kaz
#
# $FreeBSD$
#

PORTNAME=	xmbmon
PORTVERSION=	106p1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/
DISTNAME=	${PORTNAME}${PORTVERSION:S/p/pl/}

MAINTAINER=	kaz@kobe1995.net

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

DOCS=	00README.txt	00READMEj.txt	DEBUG_Info	xmbmon.resources

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>

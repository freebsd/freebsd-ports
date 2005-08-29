# New ports collection makefile for:	p5-Senna
# Date created:		May 28 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Senna
PORTVERSION=	0.08${SNAPREV}
CATEGORIES=	textproc
MASTER_SITES=	http://dist.bsdlab.org/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-snap-${SNAPREV}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for Embeddable Fulltext Search Engine

WRKSRC=		${WRKDIR}/${PORTNAME}
PERL_MODBUILD=	YES
CFLAGS+=	-I${LOCALBASE}/include
MAN3=		Senna.3 Senna::Cursor.3 Senna::Index.3 Senna::Result.3

SNAPREV=	r39

tardist:
	svn export svn://dev.razil.jp/senna-perl/trunk Senna
	tar cfvz ${PORTNAME}-snap-${SNAPREV}.tar.gz Senna
	${RM} -rf Senna

.include <bsd.port.mk>

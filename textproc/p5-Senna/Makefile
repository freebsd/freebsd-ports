# New ports collection makefile for:	p5-Senna
# Date created:		May 28 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Senna
PORTVERSION=	0.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/D/DM/DMAKI/
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for Embeddable Fulltext Search Engine

BUILD_DEPENDS=	senna-cfg:${PORTSDIR}/textproc/senna
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	YES
CFLAGS+=	-I${LOCALBASE}/include
MAN3=		Senna.3 Senna::Cursor.3 Senna::Index.3 Senna::Result.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later
.endif

.include <bsd.port.post.mk>

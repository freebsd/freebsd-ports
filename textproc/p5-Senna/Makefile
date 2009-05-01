# New ports collection makefile for:	p5-Senna
# Date created:		May 28 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Senna
PORTVERSION=	0.51
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/D/DM/DMAKI/
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for Embeddable Fulltext Search Engine

BUILD_DEPENDS=	senna-cfg:${PORTSDIR}/textproc/senna
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	YES
CONFIGURE_ARGS+=</dev/null
CFLAGS+=	-I${LOCALBASE}/include
MAN3=		Senna.3 \
	Senna::Constants.3 Senna::Index.3 Senna::OptArg::Select.3 \
	Senna::OptArg::Sort.3 Senna::Query.3 Senna::RC.3 Senna::Record.3 \
	Senna::Records.3 Senna::Set.3 Senna::Snippet.3 Senna::Symbol.3 \
	Senna::Values.3

.include <bsd.port.mk>

# New ports collection makefile for:	textproc/p5-Text-Aspell
# Date created:				4 March 2005
# Whom:					lars.eggert@gmx.net
#
# $FreeBSD$
#

PORTNAME=	Text-Aspell
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Perl interface to the GNU Aspell library

BUILD_DEPENDS=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=INC=-I${LOCALBASE}/include \
		"LIBS=-L${LOCALBASE}/lib -laspell"

MAN3=		Text::Aspell.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later
.endif

.include <bsd.port.post.mk>

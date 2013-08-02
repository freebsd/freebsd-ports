# Created by: lars.eggert@gmx.net
# $FreeBSD$

PORTNAME=	Text-Aspell
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the GNU Aspell library

BUILD_DEPENDS=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS+=INC=-I${LOCALBASE}/include \
		"LIBS=-L${LOCALBASE}/lib -laspell"

MAN3=		Text::Aspell.3

.include <bsd.port.mk>

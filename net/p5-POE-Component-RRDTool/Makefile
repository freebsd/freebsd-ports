# New ports collection makefile for:	POE-Component-RRDTool
# Date created:	   05 July 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-RRDTool
PORTVERSION=	0.14
CATEGORIES=	net perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${LOCALBASE}/bin/rrdtool:${PORTSDIR}/net/rrdtool
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		POE::Component::RRDTool.3

.include <bsd.port.mk>

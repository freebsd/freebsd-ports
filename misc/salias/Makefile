# ex:ts=8
# New ports collection makefile for:	salias
# Date created:			May 16, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	salias
PORTVERSION=	0.1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	salias.1

.include <bsd.port.mk>

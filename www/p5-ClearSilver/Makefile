# New ports collection makefile for:	p5-ClearSilver
# Date created:				June 25, 2006
# Whom:					Rink Springer <rink@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ClearSilver
PORTVERSION=	0.10.4
CATEGORIES=	www perl5
MASTER_SITES=	http://www.clearsilver.net/downloads/
PKGNAMEPREFIX=	p5-
DISTNAME=	clearsilver-${PORTVERSION}

MAINTAINER=	rink@FreeBSD.org
COMMENT=	Perl bindings for fast and powerful template system

BUILD_DEPENDS=	${LOCALBASE}/bin/cstest:${PORTSDIR}/www/clearsilver

WRKSRC=		${WRKDIR}/${DISTNAME}/perl
PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include/ClearSilver"

MAN3=		ClearSilver.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-ClearSilver
# Date created:				June 25, 2006
# Whom:					Rink Springer <rink@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ClearSilver
PORTVERSION=	0.10.5
PORTREVISION=	1
CATEGORIES=	www perl5
PKGNAMEPREFIX=	p5-
DISTFILES=

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl bindings for fast and powerful template system

BUILD_DEPENDS=	${LOCALBASE}/lib/libneo_cs.a:${PORTSDIR}/www/clearsilver
EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/www/clearsilver:extract

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include/ClearSilver"

MAN3=		ClearSilver.3

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/www/clearsilver && ${MAKE} -V WRKSRC`/perl ${WRKSRC}

.include <bsd.port.mk>

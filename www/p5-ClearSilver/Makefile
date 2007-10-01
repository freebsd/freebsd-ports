# New ports collection makefile for:	p5-ClearSilver
# Date created:				June 25, 2006
# Whom:					Rink Springer <rink@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ClearSilver
PORTVERSION=	0.10.5
CATEGORIES=	www perl5
PKGNAMEPREFIX=	p5-
DISTFILES=

MAINTAINER=	rink@FreeBSD.org
COMMENT=	Perl bindings for fast and powerful template system

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/www/clearsilver:extract
RUN_DEPENDS=	${LOCALBASE}/bin/cstest:${PORTSDIR}/www/clearsilver

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include/ClearSilver"

MAN3=		ClearSilver.3

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/www/clearsilver && ${MAKE} -V WRKSRC`/perl ${WRKSRC}

.include <bsd.port.mk>

# ex:ts=8
# New ports collection makefile for:	vshnu
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vshnu
PORTVERSION=	1.0304
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.cs.indiana.edu/~kinzler/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	New Visual Shell

BUILD_DEPENDS=	${SITE_PERL}/Term/Screen.pm:${PORTSDIR}/devel/p5-Term-Screen
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

# ex:ts=8
# New ports collection makefile for:	borZoi
# Date created:			Aug 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	borzoi
PORTVERSION=	0.9.1
CATEGORIES=	security
MASTER_SITES=	http://www1.kcn.ne.jp/~anthony/software/
DISTNAME=	borZoi-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl
RUN_DEPENDS=	${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

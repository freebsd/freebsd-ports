# New ports collection makefile for:	jtop
# Date created:				27 March 2004
# Whom:					Pavel Novikov
#
# $FreeBSD$
#

PORTNAME=	jtop
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ext.by/jtop/

MAINTAINER=	pavel@ext.by
COMMENT=	Wrapper to top(1) that maps pids to jails

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN1=		jtop.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/jtop

.include <bsd.port.mk>

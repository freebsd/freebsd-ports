# New ports collection makefile for:	jps
# Date created:				27 March 2004
# Whom:					Pavel Novikov
#
# $FreeBSD$
#

PORTNAME=	jps
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ext.by/jps/

MAINTAINER=	pavel@ext.by
COMMENT=	Wrapper to ps(1) that maps pids to jails

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN1=		jps.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/jps

.include <bsd.port.mk>

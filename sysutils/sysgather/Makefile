# New ports collection makefile for:	sysgather
# Date created:				16 December 2005
# Whom:					roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sysgather
PORTVERSION=	1.0.b5
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/sysgather/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Keep configuration files under version control

BUILD_DEPENDS=	${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes

MAN1=		sysgather.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
MAKE_ENV+=	PODCHECKER=true PODCHECKER_ARGS=
.endif

.include <bsd.port.post.mk>

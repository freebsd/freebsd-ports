# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	debhelper
PORTVERSION=	9.20140817
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper programs for debian/rules

LICENSE=	GPLv2

MAKE_ARGS=	PREFIX=${PREFIX} SITE_PERL=${SITE_PERL}
NO_BUILD=	yes
USES=		gmake perl5 shebangfix
WRKSRC=		${WRKDIR}/${PORTNAME}

SHEBANG_FILES=	dh*

.include <bsd.port.mk>

# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	debhelper
PORTVERSION=	11.1.5
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper programs for debian/rules

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

PORTSCOUT=	limit:^[0-9\.]*$$

MAKE_ARGS=	PREFIX=${PREFIX} SITE_PERL=${PREFIX}/${SITE_PERL_REL}
NO_ARCH=	yes
NO_BUILD=	yes
USES=		gmake perl5 shebangfix tar:xz
WRKSRC=		${WRKDIR}/${PORTNAME}

SHEBANG_FILES=	dh*

post-patch:
	@${RM} ${WRKSRC}/*.orig

.include <bsd.port.mk>

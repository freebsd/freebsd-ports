PORTNAME=	debhelper
PORTVERSION=	13.26
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
DISTNAME=	debhelper_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper programs for debian/rules
WWW=		https://salsa.debian.org/debian/debhelper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

USES=		gmake perl5 shebangfix tar:xz

MAKE_ARGS=	PREFIX=${PREFIX} SITE_PERL=${PREFIX}/${SITE_PERL_REL} VERSION=${PORTVERSION}
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/work

PORTSCOUT=	limit:^[0-9\.]*$$

SHEBANG_FILES=	dh*

post-patch:
	@${RM} ${WRKSRC}/*.orig

.include <bsd.port.mk>

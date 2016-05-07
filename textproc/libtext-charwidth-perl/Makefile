# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	libtext-charwidth-perl
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Documentation gettext tools

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		perl5 tar:bz2
USE_PERL5=	configure

post-extract:
	@${MV} ${WRKSRC}.orig ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/CharWidth/CharWidth.so

.include <bsd.port.mk>

# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	libtext-wrapi18n-perl
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/libt/libtext-wrapi18n-perl
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Documentation gettext tools

BUILD_DEPENDS=	libtext-charwidth-perl>=0:${PORTSDIR}/textproc/libtext-charwidth-perl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${MV} ${WRKSRC}.orig ${WRKSRC}

.include <bsd.port.mk>

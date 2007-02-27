# New ports collection makefile for:	libtext-wrapi18n-perl
# Date created:				08 Januar 2006
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	libtext-wrapi18n-perl
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/libt/libtext-wrapi18n-perl
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Documentation gettext tools

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/CharWidth.pm:${PORTSDIR}/textproc/libtext-charwidth-perl

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PERL_CONFIGURE=	yes

MAN3=		Text::WrapI18N.3

post-extract:
	@${MV} ${WRKSRC}.orig ${WRKSRC}

.include <bsd.port.mk>

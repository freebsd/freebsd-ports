# New ports collection makefile for:	mcstas
# Date created:			Apr 26, 2004
# Whom:				Joerg Pulz <Joerg.Pulz@frm2.tum.de>
#
# $FreeBSD$

PORTNAME=	mcstas
PORTVERSION=	1.9
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://www.mcstas.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A neutron ray-trace simulation package

BUILD_DEPENDS=	pgxwin_server:${PORTSDIR}/graphics/pgplot
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PDL.pm:${PORTSDIR}/math/PDL \
		${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

STRIP=
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PERL_ARCHNAME!=	perl -V:archname

PLIST_SUB+=	PERL_PORT=perl5 PERL_ARCHNAME=${PERL_ARCHNAME:S/archname='//:S/';//}

post-configure:
		@cd ${WRKSRC}; make pgplot

.include <bsd.port.mk>

# New ports collection makefile for:	mcstas
# Date created:			Apr 26, 2004
# Whom:				Joerg Pulz <Joerg.Pulz@frm2.tum.de>
#
# $FreeBSD$

PORTNAME=	mcstas
PORTVERSION=	1.8
CATEGORIES=	science
MASTER_SITES=	http://mcstas.risoe.dk/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	Joerg.Pulz@frm2.tum.de
COMMENT=	A neutron ray-trace simulation package

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PGPLOT.pm:${PORTSDIR}/graphics/pgperl \
		${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

STRIP=
USE_GZIP=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PERL_ARCHNAME!=	perl -V:archname

PLIST_SUB+=	PERL_PORT=perl5 PERL_ARCHNAME=${PERL_ARCHNAME:S/archname='//:S/';//}

post-configure:
		@cd ${WRKSRC}; make pgplot

.include <bsd.port.mk>

# Created by: Joerg Pulz <Joerg.Pulz@frm2.tum.de>
# $FreeBSD$

PORTNAME=	mcstas
PORTVERSION=	1.12c
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://www.mcstas.org/download/ \
		http://www.c-s.li/ports/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	cs@FreeBSD.org
COMMENT=	A neutron ray-trace simulation package

LICENSE=	GPLv2

BUILD_DEPENDS=	pgxwin_server:${PORTSDIR}/graphics/pgplot
RUN_DEPENDS=	PDL>=0:${PORTSDIR}/math/PDL \
		p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk

STRIP=
USES=		perl5
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PERL_ARCHNAME!=	perl -V:archname 2>/dev/null || echo

PLIST_SUB+=	PERL_PORT=perl5 PERL_ARCHNAME=${PERL_ARCHNAME:S/archname='//:S/';//}

MAN1=		mcconvert.1 \
		mcdisplay.1 \
		mcdoc.1 \
		mcformat.1 \
		mcgui.1 \
		mcplot.1 \
		mcrun.1 \
		mcstas.1 \

NO_STAGE=	yes
post-configure:
		@cd ${WRKSRC}; make pgplot

.include <bsd.port.mk>

# New ports collection makefile for:    hunspell
# Date created:         24.07.2004
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/Hunspell/${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Improved spell-checker for Hungarian and other languages

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

CONFIGURE_ARGS=	--disable-nls --with-readline --with-ui \
		--with-libiconv-prefix=${LOCALBASE}
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_NCURSES=	yes
USE_ICONV=	yes

MANLANG=	"" hu
MAN1_EN=	hunspell.1 hunzip.1 hzip.1
MAN1_HU=	hunspell.1
MAN3_EN=	hunspell.3
MAN4_EN=	hunspell.4
MAN4_HU=	hunspell.4

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/tools/hunspell.cxx

pre-build:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>

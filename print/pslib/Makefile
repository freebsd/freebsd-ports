# ex:ts=8
# Ports collection makefile for:	pslib
# Date created:			Jul 13, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pslib
PORTVERSION=	0.2.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C-library for generating multi page PostScript documents

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_PERL5_BUILD=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>

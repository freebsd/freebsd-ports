# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	0.8
PORTREVISION=	0
CATEGORIES=	print editors
MASTER_SITES=	http://web2.altmuehlnet.de/fschmid/
DIST_SUBDIR=	${PORTNAME}
PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		Fonts.diff Palette.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@geeksrus.net

RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript-gnu
#LIB_DEPENDS+=	lcms.1:${PORTSDIR}/graphics/lcms # needs 1.0.9

USE_QT_VER=		3
USE_REINPLACE=		yes
REINPLACE_ARGS=		-i
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
#USE_AUTOMAKE_VER=	14

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/share/scribus/libs \
		%%PREFIX%%/share/scribus/plugins

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|docs icons|icons|" \
		${WRKSRC}/scribus/Makefile.in
.endif
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|share/scribus/doc|share/doc/scribus|'

.include <bsd.port.mk>

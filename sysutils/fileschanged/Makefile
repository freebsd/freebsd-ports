# New ports collection makefile for:	fileschanged
# Date created:				18 May 2004
# Whom:					Konstantin Reznichenko <kot@premierbank.dp.ua>
#
# $FreeBSD$
#

PORTNAME=	fileschanged
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility that reports when files have been altered

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam
BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone \
		help2man:${PORTSDIR}/misc/help2man

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-largp"

INFO=		fileschanged
MAN1=		fileschanged.1
PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README fileschanged.lsm
PLIST_FILES=	bin/fileschanged

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

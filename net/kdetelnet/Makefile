# New ports collection makefile for:	ktelnet
# Date created:		14 May 1998
# Whom:			Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

PORTNAME=	ktelnet
PORTVERSION=	0.63
CATEGORIES=	net kde
MASTER_SITES=	http://www.spaghetti-code.de/download/ktelnet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=1
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}" KDEDIR="${LOCALBASE}"
CONFIGURE_ARGS=	--with-extra-includes=${X11BASE}/include \
		--program-transform-name='s,k,kde,'

post-extract:
	@find ${WRKSRC} -name '*\.deps*' | xargs ${RM} -rf

post-patch:
	@cd ${WRKSRC} && aclocal

.include <bsd.port.mk>

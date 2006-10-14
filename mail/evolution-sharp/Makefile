# New ports collection makefile for:		evolution-sharp
# Date created:					20041012
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.23 2006/09/16 21:53:04 tmclau02 Exp $
#

PORTNAME=	evolution-sharp
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.11

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for evolution

BUILD_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		evolution:${PORTSDIR}/mail/evolution

USE_GNOME=	gnomehack evolutiondataserver
USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD}  's|eshellver="2.6"|eshellver="2.8"|g ; \
		s|evolution-shell-2.6|evolution-shell-2.8|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} 's|.@EBOOK_SOVERSION@||g ; \
		s|.@ECAL_SOVERSION@||g ; \
		s|.@EDS_SOVERSION@||g' \
		${WRKSRC}/evolution/evolution-sharp.dll.config.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>

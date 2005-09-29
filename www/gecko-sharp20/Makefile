# New ports collection makefile for:		gecko-sharp
# Date created:					20040825
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.6 2005/09/25 19:01:20 tmclau02 Exp $
#

PORTNAME=	gecko-sharp
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/sources/gecko-sharp-2.0/
DISTNAME=	gecko-sharp-2.0-${PORTVERSION}

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for embeding mozilla

BUILD_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		monodoc:${PORTSDIR}/devel/mono-tools
RUN_DEPENDS=	gapi2-parser:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		monodoc:${PORTSDIR}/devel/mono-tools \
		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
.else
.if ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
.else
MOZILLA=	mozilla
.endif
.endif

USE_GNOME=	gnometarget
LATEST_LINK=	gecko-sharp20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default ${PORTNAME} uses www/mozilla for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  firefox       "
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

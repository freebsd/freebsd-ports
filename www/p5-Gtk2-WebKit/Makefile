# New ports collection makefile for:	p5-Gtk2-WebKit
# Date created:		2009-01-26
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Gtk2-WebKit
PORTVERSION=	0.04
PORTREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/F/FL/FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Web content engine library for Gtk2

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2/CodeGen.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Glib/MakeHelper.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Cairo/Install/Files.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2

BROKEN=		hangs during build

PERL_CONFIGURE=	yes

MAN3=		Gtk2::WebKit.3 \
		Gtk2::WebKit::WebView.3 \
		Gtk2::WebKit::WebBackForwardList.3 \
		Gtk2::WebKit::WebSettings.3 \
		Gtk2::WebKit::index.3 \
		Gtk2::WebKit::WebFrame.3 \
		Gtk2::WebKit::NetworkRequest.3 \
		Gtk2::WebKit::WebHistoryItem.3

.include <bsd.port.mk>

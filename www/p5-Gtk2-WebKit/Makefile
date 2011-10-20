# New ports collection makefile for:	p5-Gtk2-WebKit
# Date created:		2009-01-26
# Whom:			Zane C, Bowers-Hadley <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Gtk2-WebKit
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Web content engine library for Gtk2

BUILD_DEPENDS=	p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2

MAKE_JOBS_UNSAFE=	yes

NO_PACKAGE=	Man page creation hangs on some systems for unknown reasons

PERL_CONFIGURE=	yes

MAN3=		Gtk2::WebKit.3 \
		Gtk2::WebKit::Download.3 \
		Gtk2::WebKit::GeolocationPolicyDecision.3 \
		Gtk2::WebKit::NetworkRequest.3 \
		Gtk2::WebKit::NetworkResponse.3 \
		Gtk2::WebKit::SecurityOrigin.3 \
		Gtk2::WebKit::WebBackForwardList.3 \
		Gtk2::WebKit::WebDataSource.3 \
		Gtk2::WebKit::WebDatabase.3 \
		Gtk2::WebKit::WebFrame.3 \
		Gtk2::WebKit::WebHistoryItem.3 \
		Gtk2::WebKit::WebInspector.3 \
		Gtk2::WebKit::WebNavigationAction.3 \
		Gtk2::WebKit::WebPolicyDecision.3 \
		Gtk2::WebKit::WebResource.3 \
		Gtk2::WebKit::WebSettings.3 \
		Gtk2::WebKit::WebView.3 \
		Gtk2::WebKit::WebWindowFeatures.3 \
		Gtk2::WebKit::index.3

.include <bsd.port.mk>

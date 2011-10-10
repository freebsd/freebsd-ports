# New ports collection makefile for:	p5-Tk-Pod
# Date created:		2011-10-10
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-Pod
PORTVERSION=	0.9939
CATEGORIES=	textproc tk perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Pod browser with hypertext capabilities in a Toplevel widget

BUILD_DEPENDS=	p5-Tk>=800.004:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	p5-Tk>=800.004:${PORTSDIR}/x11-toolkits/p5-Tk

PERL_CONFIGURE=	yes

MAN1=		tkmore.1 \
		tkpod.1
MAN3=		Tk::More.3 \
		Tk::Pod.3 \
		Tk::Pod::Cache.3 \
		Tk::Pod::FindPods.3 \
		Tk::Pod::Search.3 \
		Tk::Pod::Search_db.3 \
		Tk::Pod::SimpleBridge.3 \
		Tk::Pod::Text.3 \
		Tk::Pod::Tree.3 \
		Tk::Pod::Util.3 \
		Tk::Pod_usage.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Pod-Simple>=0:${PORTSDIR}/textproc/p5-Pod-Simple
RUN_DEPENDS+=	p5-Pod-Simple>=0:${PORTSDIR}/textproc/p5-Pod-Simple
.endif

.include <bsd.port.post.mk>

# ex:ts=8
# New ports collection makefile for:	htmlobject
# Date created:			Jul 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	htmlobject
PORTVERSION=	2.28
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	lib${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	HTML Document Object

BUILD_DEPENDS=	${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip

PERL_CONFIGURE=	yes

MAN3=		HTMLObject::Base.3 HTMLObject::Form.3 \
		HTMLObject::FrameSet.3 HTMLObject::HDMLCard.3 \
		HTMLObject::HDMLDeck.3 HTMLObject::Normal.3 \
		HTMLObject::ReadCookie.3 HTMLObject::Template.3 \
		HTMLObject::WAP.3 HTMLObject::WMLCard.3 \
		HTMLObject::WMLDeck.3 HTMLObject::Widgets.3 \
		HTMLObject::ErrorBase.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or higher. Please install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>

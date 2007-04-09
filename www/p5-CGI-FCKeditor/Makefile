# New ports collection makefile for:	p5-CGI-FCKeditor
# Date created:		2007-04-05
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	CGI-FCKeditor
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	This's FCKeditor Controller for Perl OOP

PERL_CONFIGURE=	yes

MAN3=		CGI::FCKeditor.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8 or above
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:    p5-Newsletter
# Date created:		2006/12/22
# Whom:	      		chinsan
#
# $FreeBSD$
#

PORTNAME=	Newsletter
PORTVERSION=	0.03
CATEGORIES=	www textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	 ../by-authors/id/K/KA/KALELE
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A Simple website based Newsletter interface

BUILD_DEPENDS=	p5-MIME-Explode>0:${PORTSDIR}/mail/p5-MIME-Explode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Newsletter::Html.3 Newsletter::Html::Templ.3 Newsletter::Html::CSS.3 \
	Newsletter::Html::Upload.3 Newsletter.3

.include <bsd.port.mk>

# New ports collection makefile for:    p5-Authen-PAM
# Date created:				Mon Oct  4 1999
# Whom:	      				Matt Behrens <matt@zigg.com>
#
# $FreeBSD$
#

PORTNAME=	Authen-PAM
PORTVERSION=	0.13.p2
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	http://www.cs.kuleuven.ac.be/~pelov/pam/download/
MASTER_SITE_SUBDIR=	Authen
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.p.*//}
DISTFILES=	${PORTNAME}-${PORTVERSION:S/.p/pre/}.tar.gz
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Authen::FAQ.3 \
		Authen::PAM.3

.include <bsd.port.mk>

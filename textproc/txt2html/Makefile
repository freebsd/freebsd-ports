# New ports collection makefile for:    txt2html
# Date created:         29 Jun 1998
# Whom:                 Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	txt2html
PORTVERSION=	2.45
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	txt2html

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert raw text to something with a little HTML formatting

BUILD_DEPENDS=	${SITE_PERL}/Getopt/ArgvFile.pm:${PORTSDIR}/devel/p5-Getopt-ArgvFile
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=	txt2html.1
MAN3=	HTML::TextToHTML.3

.include <bsd.port.mk>

# New ports collection makefile for:	quvi
# Date created:		27 March 2010
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	umph
PORTVERSION=	0.1.1
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Youtube video playlist parser for cclive and alike tools

RUN_DEPENDS=	p5-XML-DOM>=1.44:${PORTSDIR}/textproc/p5-XML-DOM \
		p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile

MAN1=		umph.1

PERL_CONFIGURE=	yes
USE_BZIP2=	yes

.include <bsd.port.mk>

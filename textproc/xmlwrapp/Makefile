# ex:ts=8
# Ports collection makefile for:	xmlwrapp
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlwrapp
PORTVERSION=	0.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://pmade.org/pjones/software/xmlwrapp/download/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_PERL5_BUILD=	yes

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.pl
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:  yahoo-messenger
# Date created:			  Sat Dec 16, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ymessenger
PORTVERSION=	0.93.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.yahoo.com/dl/unix/fbsd4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	calle.madestrand@norrgarden.se

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext

USE_GTK=	yes
NO_BUILD=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/bin/ymessenger ${PREFIX}/bin

post-extract:
	${PERL} -p -e 's/libintl\.so\.1/libintl.so.2/g' -i \
		${WRKDIR}/bin/ymessenger
.include <bsd.port.mk>

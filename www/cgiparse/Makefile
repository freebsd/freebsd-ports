# New ports collection makefile for:	cgiparse
# Date created:				30 March 1997
# Whom:					jmg
#
# $FreeBSD$
#

PORTNAME=	cgiparse
PORTVERSION= 	0.9a
CATEGORIES=	devel www
MASTER_SITES=	http://resnet.uoregon.edu/~gurney_j/jmpc/dist/	\
		http://www.funkthat.com/~jmg/

MAINTAINER=	jmg@FreeBSD.org

BROKEN=		"Install script contains errors"

LIB_DEPENDS=	mime.1:${PORTSDIR}/devel/mime:install

GNU_CONFIGURE=	yes
MAN3=		cgiclose.3 cgigetvalue.3 cginewquerystr.3

.include <bsd.port.mk>

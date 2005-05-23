# ex:ts=8
# New ports collection makefile for:	argparse
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	argparse
PORTVERSION=	1.0.1
CATEGORIES=	misc
MASTER_SITES=	http://kingleo.home.pages.at/development/cpp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for commandline parsing for shell scripts

LIB_DEPENDS=	LeoArg.2:${PORTSDIR}/devel/leoarg

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/argparse
PORTDOCS=	*
MAN1=	argparse.1

.include <bsd.port.mk>

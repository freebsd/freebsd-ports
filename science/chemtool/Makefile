# New ports collection makefile for:	chemtool
# Date created:			Mar 31, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chemtool
PORTVERSION=	1.5
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	transfig:${PORTSDIR}/print/transfig

USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	chemtool.1 cht.1

post-install:
	${MKDIR} ${PREFIX}/share/examples/chemtool
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/chemtool

.include <bsd.port.mk>

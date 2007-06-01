# New ports collection makefile for:		newsbeuter
# Date created:					2007-06-01
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	newsbeuter
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	http://synflood.at/newsbeuter/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	An RSS feed reader for the text console

LIB_DEPENDS=	stfl.0:${PORTSDIR}/devel/stfl \
		nxml.0:${PORTSDIR}/textproc/libnxml \
		mrss.0:${PORTSDIR}/textproc/libmrss \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5_BUILD=yes

MAN1=	newsbeuter.1 podbeuter.1

post-patch:
	${REINPLACE_CMD} -e "s,share/man,man,; \
				s,prefix,PREFIX," ${WRKSRC}/Makefile

.include <bsd.port.mk>

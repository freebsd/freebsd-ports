# New ports collection makefile for:   xmlcharent
# Date created:                31 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	xmlcharent
PORTVERSION=	0.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	fuyuki@hadaly.org

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

XMLDIR=		${PREFIX}/share/xml/${PORTNAME}

do-install:
	${MKDIR} ${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ent ${FILESDIR}/catalog ${XMLDIR}

.include <bsd.port.mk>

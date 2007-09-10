# New ports collection makefile for:	vee
# Date created:		24 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vee
DISTVERSION=	0.9.9-epsilon
CATEGORIES=	www
MASTER_SITES=	http://www.0x743.com/vee/ CENKES
# Also here: http://code.google.com/p/vee/
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Tiny CLI blogging tool

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -Ee 's|^function ([[:graph:]]+)|\1 ()|' ${WRKSRC}/bin/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>

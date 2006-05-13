# New ports collection makefile for:	keyprint
# Date created:		Sat May 29 02:05:00 PDT 1999
# Whom:			mharo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	opieprint
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.inner.net/pub/opie/contrib/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.gz

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	Output postscript with 100 OPIE passwords credit card sized

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5_RUN=	yes

EXTRACT_AFTER_ARGS= > ${WRKSRC}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local/bin/perl,${PERL},' ${WRKSRC}/opieprint

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/opieprint ${PREFIX}/bin

.include <bsd.port.mk>

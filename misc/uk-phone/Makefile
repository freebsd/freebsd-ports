# New ports collection makefile for:	United Kingdom phone codes.
# Date created:         1998-01-01
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	uk-phone
PORTVERSION=	2.3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.Awfulhak.org/pub/uk-phone/ \
		http://people.FreeBSD.org/~brian/uk-phone/
EXTRACT_SUFX=	.gz

MAINTAINER=	brian@FreeBSD.org

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/uk.phone
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/uk.phone ${PREFIX}/share/misc

.include <bsd.port.mk>

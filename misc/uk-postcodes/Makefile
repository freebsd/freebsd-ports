# New ports collection makefile for:	United Kingdom post codes.
# Date created:         1998-01-01
# Whom:                 wosch
#
# $FreeBSD$

PORTNAME=	uk-postcodes
PORTVERSION=	2.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.Awfulhak.org/pub/uk-postcodes/ \
		http://people.FreeBSD.org/~brian/uk-postcodes/
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	United Kingdom post codes

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/uk.postcodes
NO_BUILD=	yes
PLIST_FILES=	share/misc/uk.postcodes

do-install:
	${INSTALL_DATA} ${WRKSRC}/uk.postcodes ${PREFIX}/share/misc

.include <bsd.port.mk>

# New ports collection makefile for:	ftpmap
# Date created:		01 Nov 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	ftpmap
PORTVERSION=	0.4
CATEGORIES=	security ftp
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/ftpmap/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Identify remote FTP server software by fingerprinting

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

GNU_CONFIGURE=	yes

DOCS=		AUTHORS NEWS README THANKS

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

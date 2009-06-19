# New ports collection makefile for:	smtpmap
# Date created:				26 decembre 2002
# Whom:					Hubert Tournier <hubert@frbsd.org>
#
# $FreeBSD$
#

PORTNAME=	smtpmap
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	security mail net
MASTER_SITES=	http://www.frbsd.org/dist/

MAINTAINER=	hubert@frbsd.org
COMMENT=	An SMTP software identifier

DEPRECATED=	depends on GCC 2.95 which has not been available for 9+ months
EXPIRATION_DATE=2009-07-19

MAKE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e 's|-j 5||g' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/smtpmap ${PREFIX}/bin
	${INSTALL} -d ${DATADIR}
.for file in fingerprints-conf fingerprints-return fingerprints-rfc
	${INSTALL_DATA} ${WRKSRC}/share/${file} ${DATADIR}
.endfor

.include <bsd.port.mk>

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
MASTER_SITES=	http://plasmahh.hopto.org/

MAINTAINER=	hubert@frbsd.org
COMMENT=	An SMTP software identifier

MAKE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
USE_GETOPT_LONG=yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GCC=	2.95
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

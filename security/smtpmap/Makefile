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

.if !exists(/usr/include/getopt.h)
MAKE_ENV=	LIBS="${LDFLAGS}" INC="${CPPFLAGS}"
.endif

USE_GETOPT_LONG=yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/makefile.conf
	@${REINPLACE_CMD} -e 's|\(INC)\) \(small\)|\1 $$(LIBS) \2|g' ${WRKSRC}/src/makefile
	@${REINPLACE_CMD} -e 's|-j 5||g' -e 's|@\(./inst\)|\1|g' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/smtpmap ${PREFIX}/bin
	${INSTALL} -d ${DATADIR}
.for file in fingerprints-conf fingerprints-return fingerprints-rfc
	${INSTALL_DATA} ${WRKSRC}/share/${file} ${DATADIR}
.endfor

.include <bsd.port.mk>

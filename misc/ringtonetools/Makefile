# New ports collection makefile for:	ringtonetools
# Date created:				7 June 2002
# Whom:					Michael A. Kohn <mike@mikekohn.net>
#
# $FreeBSD$
#

PORTNAME=	ringtonetools
PORTVERSION=	2.09
CATEGORIES=	misc
MASTER_SITES=	http://www.mikekohn.com/ringtonetools/

MAINTAINER=	mike@mikekohn.net
COMMENT=	Create/Convert/Listen to ringtones and logos for mobile phones

RESTRICTED=	no-commercial-use

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ringtonetools ${PREFIX}/bin
.for i in face.icon hemglass.mid ionian.rtttl usa.emelody yngwie_trilogy.rtttl
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/samples/${i} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
.endif


.include <bsd.port.mk>

# New ports collection makefile for:	ringtonetools
# Date created:				7 June 2002
# Whom:					Michael A. Kohn <mike@mikekohn.net>
#
# $FreeBSD$
#

PORTNAME=	ringtonetools
PORTVERSION=	2.01
CATEGORIES=	misc
MASTER_SITES=	http://65.108.58.129/ringtonetools/

MAINTAINER=	mike@mikekohn.net

RESTRICTED=	no-commercial-use

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ringtonetools ${PREFIX}/bin
.for i in face.icon hemglass.mid ionian.rtttl usa.imelody yngwie_trilogy.rtttl
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/samples/${i} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

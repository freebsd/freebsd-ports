# New ports collection makefile for:	yuzu
# Date created:		31 March 2000
# Whom:			Daichi GOTO
#
# $FreeBSD$
#

PORTNAME=	yuzu
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.ongs.net/yuzu/

MAINTAINER=	daichi@freebsd.org
COMMENT=	A nicer mail user agent powered by JavaMail and JFC/Swing

RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8:${PORTSDIR}/java/jdk11 \
		${LOCALBASE}/share/java/jfc-1.1.1:${PORTSDIR}/java/jfc

NO_BUILD=	yes

PLIST_SUB=	DISTNAME="${DISTNAME}"

do-install:
	${MKDIR} ${PREFIX}/share/java/${DISTNAME}
	${MKDIR} ${PREFIX}/share/java/${DISTNAME}/yuzu
	@${CP} -R ${WRKSRC}/* ${PREFIX}/share/java/${DISTNAME}/yuzu/
	@${CP} ${WRKSRC}/misc/README* ${PREFIX}/share/java/${DISTNAME}
	@${CP} -R ${WRKSRC}/misc/config ${PREFIX}/share/java/${DISTNAME}
	@${LN} -s ${PREFIX}/share/java/${DISTNAME}/yuzu/yuzu.sh ${PREFIX}/bin/yuzu

.include <bsd.port.mk>

# New ports collection makefile for:    ap-utils
# Date created:		2002/07/10
# Whom:			Jerry A! <jerry@thehutt.org>
#
# $FreeBSD$
#

PORTNAME=	ap-utils
PORTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	http://ap-utils.polesye.net/files/ \
		http://web.cs.cmu.edu/~dpelleg/download/

MAINTAINER=	daniel+aputils@pelleg.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAN8=		ap-trapd.8 ap-mrtg.8 ap-atmel.8 ap-nwn.8

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/FAQ ${DOCSDIR}
.endif

.include <bsd.port.mk>

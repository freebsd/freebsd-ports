# New ports collection makefile for: pim6-sd
# Date created:  2 Jun 2001
# Whom:   dwcjr
#
# $FreeBSD$
#

PORTNAME=	pim6dd
PORTVERSION=	20040819a
PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	suz@FreeBSD.org
COMMENT=	PIM for IPv6 dense mode daemon

USE_REINPLACE=	yes

MAN5=		pim6dd.conf.5
MAN8=		pim6dd.8
MANCOMPRESSED=	yes

DOCS=		LICENSE.mrouted LICENSE.pimd

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
.for file in Makefile.inc pim6dd/pathnames.h pim6dd/pim6dd.8
	@${REINPLACE_CMD} -e 's./usr/local/v6.${PREFIX}.g' ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/pim6dd.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for file in ${DOCS}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${file} ${PREFIX}/share/doc/${PORTNAME}
	@${ECHO_CMD} share/doc/${PORTNAME}/${file} >>${TMPPLIST}
.endfor
	@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}" >>${TMPPLIST}
.endif

.include <bsd.port.mk>

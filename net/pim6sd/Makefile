# New ports collection makefile for: pim6-sd
# Date created:  2 Jun 2001
# Whom:   dwcjr
#
# $FreeBSD$
#

PORTNAME=	pim6sd
PORTVERSION=	20040819a
PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	suz@FreeBSD.org
COMMENT=	PIM for IPv6 sparse mode daemon

NO_CDROM=	"Cannot be sold for profit"

USE_REINPLACE=	yes

MAN5=		pim6sd.conf.5
MAN8=		pim6sd.8
MANCOMPRESSED=	yes

DOCS=		BUGS.TODO BUGS.V6 LICENSE.mrouted LICENSE.pim6dd \
		LICENSE.pim6sd LICENSE.pimd README README.first README.SSM

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
.for file in Makefile.inc pim6sd/pathnames.h pim6sd/pim6sd.8
	@${REINPLACE_CMD} -e 's./usr/local/v6.${PREFIX}.g' ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/pim6sd.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for file in ${DOCS}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${file} ${PREFIX}/share/doc/${PORTNAME}
	@${ECHO_CMD} share/doc/${PORTNAME}/${file} >>${TMPPLIST}
.endfor
	@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}" >>${TMPPLIST}
.endif

.include <bsd.port.mk>

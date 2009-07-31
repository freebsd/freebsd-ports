# New ports collection makefile for: http-analyze
# Date created:		Fri Jul 11 06:11:41 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$

PORTNAME=	http-analyze
PORTVERSION=	2.01
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}/sources/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast Log-Analyzer for web servers

PATCH_DEPENDS=	gif2png:${PORTSDIR}/graphics/gif2png
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

MAN1=		http-analyze.1

post-patch:
	@${ECHO_MSG} "Converting GIFs to PNG format"
	@${FIND} "${WRKSRC}/files/btn" -name "*.gif" -type f \
		-exec gif2png -d -O {} \;

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/http-analyze.pdf ${WRKSRC}/http-analyze.ps \
		${DOCSDIR}
.endif

.include <bsd.port.mk>

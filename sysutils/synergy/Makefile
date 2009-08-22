# New ports collection makefile for:	synergy
# Date created:		26 March 2003
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	synergy
PORTVERSION= 	1.3.1
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}2/Sources/${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

GNU_CONFIGURE=	yes
USE_XORG=	ice xtst x11 sm
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@cd ${WRKSRC}/doc && ${TAR} cf - *.html *.css images | \
		${TAR} -C ${DOCSDIR} -xpf -
.endif
	${MKDIR} ${PREFIX}/share/examples/synergy
	${INSTALL_DATA} ${WRKSRC}/examples/synergy.conf ${PREFIX}/share/examples/synergy

.include <bsd.port.mk>

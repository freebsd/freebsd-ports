# New ports collection makefile for:	mutt_vc_query
# Date created:				14 May 2003
# Whom:	      				Oliver Braun
#
# $FreeBSD$
#

PORTNAME=	mutt_vc_query
PORTVERSION=	002
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rolo

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A vCard query utility for mutt

RUN_DEPENDS=	${LOCALBASE}/lib/libvc.so:${PORTSDIR}/devel/libvc
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include \
		-L${PREFIX}/lib

MAN1=		mutt_vc_query.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for DOC in AUTHORS ChangeLog NEWS README THANKS
	@${INSTALL_DATA} ${WRKSRC}/${DOC} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

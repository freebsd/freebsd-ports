# New ports collection makefile for:   freefem
# Date created:        20 December 1996
# Whom:                Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	freefem
PORTVERSION=	3.5.8
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	SF/kfem/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A language for the Finite Element Method

USE_XORG=	ice sm x11 xt
USE_GNOME=	gnometarget
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

MAN1=		freefem.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 |\$$CXXFLAGS |g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|admin doc freefem|admin freefem|g ; \
		 s|^install-data-am:|install-data-am: #|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.pde ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>

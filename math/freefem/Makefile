# New ports collection makefile for:   freefem
# Date created:        20 December 1996
# Whom:                Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	freefem
PORTVERSION=	3.5.7
CATEGORIES=	math science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kfem

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A language for the Finite Element Method

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-optimization
INSTALLS_SHLIB=	yes

MAN1=		freefem.1

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 |\$$CXXFLAGS |g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|debian doc freefem|debian freefem|g ; \
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

.include <bsd.port.mk>

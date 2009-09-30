# New ports collection makefile for:	clhep
# Date created:				6 May 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	clhep
PORTVERSION=	2.0.4.3
CATEGORIES=	science
MASTER_SITES=	http://wwwasd.web.cern.ch/wwwasd/lhc++/clhep/DISTRIBUTION/distributions/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN

WRKSRC=		${WRKDIR}/${PORTVERSION}/${PORTNAME:U}

USE_GNOME=	gnometarget
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gmake
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=	Does not compile on FreeBSD 6.X
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		 '/AM_CXXFLAGS=/s|-O ||g'

.include <bsd.port.post.mk>

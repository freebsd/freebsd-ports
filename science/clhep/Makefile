# Created by: will
# $FreeBSD$

PORTNAME=	clhep
PORTVERSION=	2.1.0.1
CATEGORIES=	science
MASTER_SITES=	http://wwwasd.web.cern.ch/wwwasd/lhc++/clhep/DISTRIBUTION/tarFiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN

WRKSRC=		${WRKDIR}/${PORTVERSION}/${PORTNAME:tu}

USES=		gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gmake
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=	Does not compile on FreeBSD 6.X
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		 '/AM_CXXFLAGS=/s|-O ||g'

.include <bsd.port.post.mk>

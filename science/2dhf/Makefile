# New ports collection makefile for:	2dhf
# Date created:				24 July 2003
# Whom:					NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	2dhf
PORTVERSION=	2003.02
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://staff.csc.fi/~laaksone/2d/admin/
DISTNAME=	${PORTNAME}_02.03
EXTRACT_SUFX=	.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A Numerical Hartree-Fock Program for Diatomic Molecules

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		atlas:${PORTSDIR}/math/atlas

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
.if (${MACHINE_ARCH} == "i386")
FFLAGS+=	-mfancy-math-387
.endif # i386
.endif

pre-everything::
	@${ECHO_CMD} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_REINPLACE=  yes

do-extract:
	${MKDIR} ${WRKSRC}
	@(cd ${WRKSRC} ;  ${TAR} xfz ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})

post-patch:
	@${REINPLACE_CMD} -e 's,%%FC%%,${FC},g ; \
	s,%%FFLAGS%%,${FFLAGS},g ; \
	s,%%CC%%,${CC},g ; \
	s,%%CFLAGS%%,${CFLAGS},g ; \
	s,%%LOCALBASE%%,${LOCALBASE},g' \
	 ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	 ${WRKSRC}/bin/xhf
do-build:
	@${MKDIR} ${WRKSRC}/obj ; cd ${WRKSRC} ; ${GMAKE}

do-install:
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} bin/x2dhf ${PREFIX}/bin/x2dhf
	@cd ${WRKSRC} ; ${INSTALL_SCRIPT}  bin/xhf   ${PREFIX}/bin/xhf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc ; ${INSTALL_DATA} 2dhf.pdf users_guide.pdf ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/users_guide
	@cd ${WRKSRC}/doc/users_guide ; ${INSTALL_DATA} * ${DOCSDIR}/users_guide
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ ; ${TAR} -chf - . | \
		${TAR} -xf - -C ${EXAMPLESDIR}
.endif
.include <bsd.port.mk>

# vim: tabstop=8 softtabstop=0 noexpandtab
# Ports collection Makefile for:	jags
# Date created:		21 April 2004
# Whom:			Eric van Gyzen <vangyzen@stat.duke.edu>
#
# $FreeBSD$
#

PORTNAME=	mcmc-jags
PORTVERSION=	2.1.0
CATEGORIES=	math
MASTER_SITES=	SF:1,2,3
MASTER_SITE_SUBDIR=	${PORTNAME}/JAGS/2.x/Source/:1 \
		${PORTNAME}/Examples/2.0/:2 \
		${PORTNAME}/Manuals/2.0/:3
DISTFILES=	${DISTNAME:S/mcmc-//:U}${EXTRACT_SUFX}:1
.if !defined(NOPORTDOCS)
DISTFILES+=	classic-bugs.tar.gz:2 jags_developer_manual.pdf:3 \
		jags_installation_manual.pdf:3 jags_user_manual.pdf:3
EXTRACT_ONLY=	${DISTNAME:S/mcmc-//:U}${EXTRACT_SUFX}
.endif

MAINTAINER=	bf1783@gmail.com
COMMENT=	Just Another Gibbs Sampler

OPTIONS=	ATLAS "use ATLAS libraries instead of BLAS and LAPACK" off

DIST_SUBDIR=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PKGNAME:S/mcmc-//:U}

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_FORTRAN=	yes
USE_LDCONFIG=	yes
USE_BISON=	build
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
CONFIGURE_ARGS=	--with-lapack=-lalapack --with-blas=-lf77blas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
CONFIGURE_ARGS=	--with-lapack=-llapack --with-blas=-lblas
.endif

post-patch:
	${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/etc/Makefile.in
	${REINPLACE_CMD} \
		-e '/@WINDOWS_FALSE@bin_SCRIPTS =/s/jags/mcmc-&/' \
		-e '/CLEANFILES =/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@jags:/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@.*rm -f jags/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@.*mv jags.tmp jags/s/jags/mcmc-&/2' \
		${WRKSRC}/src/terminal/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for _M in developer installation user
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/jags_${_M}_manual.pdf \
		${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	( cd ${EXAMPLESDIR}; \
	  ${PAX} -rzf ${DISTDIR}/${DIST_SUBDIR}/classic-bugs.tar.gz \
	    -s ':^classic-bugs/*::' )
	${SED} -i '' \
		-e '\|JAGS ?=|{s|/usr/local|${PREFIX}|;s|jags|mcmc-&|;}' \
		${EXAMPLESDIR}/vol[12]/Makefile
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.endif

.include <bsd.port.mk>

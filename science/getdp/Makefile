# New ports collection makefile for:  getdp
# Date created:               25 September 2004
# Whom:                       Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	getdp
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.geuz.org/getdp/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A rather general finite element solver using mixed finite elements

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw	\
		gsl.7:${PORTSDIR}/math/gsl	\
		lapack.3:${PORTSDIR}/math/lapack

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-fftw-prefix=${LOCALBASE}	\
		--with-gsl-prefix=${LOCALBASE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		getdp.1

EXAMPLES=	Magnetostatics.pro README solver.par test.geo test.msh test.pro

.if defined(WITH_MULTIHARMONIC)
CONFIGURE_ARGS+=	--enable-multiharmonic
.endif

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
. if ${PERL_LEVEL} < 500600
NOPORTDOCS=	yes
. else
ALL_TARGET=	all doc
BUILD_DEPENDS+=	texi2pdf:${PORTSDIR}/print/teTeX-base	\
		dvips:${PORTSDIR}/print/dvipsk-tetex
USE_PERL5_BUILD=	yes
. endif
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/getdp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${DOCSDIR} && ${TAR} xfz ${WRKSRC}/${PORTNAME}-${PORTVERSION}-doc.tgz
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/demos/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===>  Examples installed in ${EXAMPLESDIR}."
.endif

.if defined(MAINTAINER_MODE)
test:	install
	cd ${WRKSRC}/demos && ${PORTNAME} test.pro -solve MagSta_phi
.endif

.include <bsd.port.post.mk>

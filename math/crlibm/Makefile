# New ports collection makefile for:	crlibm
# Date created:		10 January 2012
# Whom:			bf@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	crlibm
DISTVERSION=	1.0beta4
CATEGORIES=	math
MASTER_SITES=	http://lipforge.ens-lyon.fr/frs/download.php/%SUBDIR%/:1,2,3 \
		LOCAL/bf:4
MASTER_SITE_SUBDIR=	162/:1 153/:2 154/:3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1,4
.if make(makesum) || !defined(NOPORTDOCS)
DISTFILES+=	crlibm-1.0beta3.pdf:2,4 tripledoubleprocedures-1.0beta3.pdf:3,4
.endif
DIST_SUBDIR=	crlibm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Correctly-rounded mathematics library

LICENSE=	LGPL21

LIB_DEPENDS=	mpfr.4:${PORTSDIR}/math/mpfr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS =	--enable-mpfr
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

#7-STABLE has log2() in libm after r226457 on 17 Oct 2011, but
#there was no accompanying OSVERSION bump
.if ${OSVERSION} < 802502 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900027)
post-patch:
	@${REINPLACE_CMD} \
	-e '/testfun_libm[[:blank:]]*=[[:blank:]]*log2;/s/log2/NULL/' \
		${WRKSRC}/tests/test_common.c

.endif

post-build:
	@cd ${WRKSRC}; ${STRIP_CMD} -x libcrlibm.a scs_lib/libscs.a

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} check

.if !defined(NOPORTDOCS)
PORTDOCS=	${DISTFILES:C|\:.*||:M*.pdf}

post-install:
	@${INSTALL_DATA} -d ${DOCSDIR}
	@cd ${_DISTDIR}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.endif

.include <bsd.port.post.mk>

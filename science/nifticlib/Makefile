# $FreeBSD$

PORTNAME=	nifticlib
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	science graphics
MASTER_SITES=	SF/niftilib/nifticlib/nifticlib_2_0_0

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Neuroimaging Informatics Technology Initiative data format

LICENSE=	PD

USES=		gmake

# AFNI currently has nifti embedded in the distfile and installs the
# nifti bins by itself.
CONFLICTS=	afni-[0-9]* dbh-[0-9]*

CFLAGS+=	-fPIC
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${FILESDIR}/nifticlib.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

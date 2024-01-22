PORTNAME=	nifticlib
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	science graphics
MASTER_SITES=	SF/niftilib/nifticlib/nifticlib_2_0_0

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Neuroimaging Informatics Technology Initiative data format
WWW=		https://nifti.nimh.nih.gov/

LICENSE=	PD

USES=		gmake

# AFNI currently has nifti embedded in the distfile and installs the
# nifti bins by itself.
CONFLICTS=	afni dbh

CFLAGS+=	-fPIC
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${FILESDIR}/nifticlib.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

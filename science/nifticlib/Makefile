PORTNAME=	nifticlib
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
CATEGORIES=	science graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Neuroimaging Informatics Technology Initiative data format
WWW=		https://nifti.nimh.nih.gov/

LICENSE=	PD

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	NIFTI-Imaging
GH_PROJECT=	nifti_clib

CONFLICTS=	dbh	# dbh.h

CFLAGS+=	-fPIC
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${FILESDIR}/nifticlib.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

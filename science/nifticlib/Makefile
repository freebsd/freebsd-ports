# Created by: Jason W. Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	nifticlib
PORTVERSION=	2.0.0
CATEGORIES=	science graphics
MASTER_SITES=	SF/niftilib/nifticlib/nifticlib_2_0_0

MAINTAINER=	jwbacon@tds.net
COMMENT=	Neuroimaging Informatics Technology Initiative data format

# LICENSE=	public domain

USES=		gmake
MAKE_JOBS_UNSAFE=yes

# AFNI currently has nifti embedded in the distfile and installs the
# nifti bins by itself.
CONFLICTS=	afni-[0-9]* dbh-[0-9]*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${FILESDIR}/nifticlib.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

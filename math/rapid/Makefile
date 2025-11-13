PORTNAME=	rapid
PORTVERSION=	2.01
PORTREVISION=	1
CATEGORIES=	math science graphics
MASTER_SITES=	http://www.cs.sunysb.edu/~algorith/implement/RAPID/distrib/
DISTNAME=	RAPID_v2_01

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Robust and Accurate Polygon Interference Detection
WWW=		http://www.cs.unc.edu/~geom/OBB/OBBT.html

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_TEXT=	For any commercial purpose, you must request a license from \
		http://www.cs.unc.edu/~geom/OBB/OBBT.html
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell no-pkg-mirror \
		auto-accept

BROKEN=			unfetchable
EXPIRATION_DATE=	2025-12-31

SUB_FILES=	pkg-message

ALL_TARGET=
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=		V=1

.include <bsd.port.pre.mk>

post-extract:
	${REINPLACE_CMD} -E "s/friend RAPID_Collide/friend int RAPID_Collide/" ${WRKSRC}/RAPID_private.H

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/RAPID
	${INSTALL_DATA}	${WRKSRC}/*.H ${STAGEDIR}${PREFIX}/include/RAPID
	${INSTALL_DATA}	${WRKSRC}/libRAPID.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${FILESDIR}/rapid.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>

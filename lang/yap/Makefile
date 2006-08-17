# ex:ts=8
# New ports collection makefile for:	yap
# Date created:			Apr 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yap
PORTVERSION=	5.1.1
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	http://www.ncc.up.pt/~vsc/Yap/current/
DISTNAME=	Yap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance Prolog compiler

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4

BROKEN=		Does not compile

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

INFO=		yap

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -f ${WRKSRC}/docs/*.info*

post-patch:
	@${REINPLACE_CMD} -e 's|VERSION}|VERSION:}|g' ${WRKSRC}/docs/yap.tex
	@${REINPLACE_CMD} -e "s,make),${GMAKE})," \
		-e "s,make install,${GMAKE} install," ${WRKSRC}/Makefile.in
	@${GREP} -lR '<malloc\.h>' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's,<malloc\.h>,<stdlib.h>,'

post-build:
	cd ${WRKSRC}/docs && makeinfo --no-split yap.tex

pre-install:
	@${MKDIR} ${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/docs/yap.info ${PREFIX}/${INFO_PATH}

post-install:
	@${FIND} ${PREFIX}/share/Yap ! -type d | \
		${SED} "s,^${PREFIX},," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/Yap -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX},@dirrm ," >> ${TMPPLIST}

.include <bsd.port.post.mk>

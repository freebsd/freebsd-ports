PORTNAME=	rdist
DISTVERSION=	7.0.0-alpha10
CATEGORIES=	net
MASTER_SITES=	http://www.magnicomp.com/download/rdist/
PKGNAMESUFFIX=	7

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Network file distribution/synchronisation utility
WWW=		https://www.magnicomp.com/

LICENSE=	BSD3CLAUSE

CONFLICTS=	rdist6

USES=		gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=		${STAGEDIR}/${PREFIX}
GNU_CONFIGURE_MANPREFIX=	${STAGEDIR}/${PREFIX}/share

INSTALL_TARGET=	install install.man

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
RUN_DEPENDS+=	rsh:net/bsdrcmds
.endif

do-build:
	@(cd ${WRKSRC} && gmake)

do-install:
	@(cd ${WRKSRC} && gmake install)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rdist
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rdistd

.include <bsd.port.post.mk>

# New ports collection makefile for:	dazuko
# Date created:				01 March 2004
# Whom:					Rob Evers <rob@debank.tv>
#
# $FreeBSD$

PORTNAME=	dazuko
PORTVERSION=	2.3.9
CATEGORIES=	security
MASTER_SITES=	http://dazuko.dnsalias.org/files/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A common interface for 3rd party file access control

HAS_CONFIGURE=	yes
SUB_FILES=	pkg-message

OPTIONS=	EXAMPLEC	"Install C example programs"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800014
BROKEN=	does not build
.endif

.if defined(WITH_EXAMPLEC)
PLIST_FILES=	%%EXAMPLESDIR%%/example %%EXAMPLESDIR%%/example_mt
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

post-configure:
	${REINPLACE_CMD} -e 's|^NOMAN|NO_MAN|g' ${WRKSRC}/library/Makefile

do-install:
.if defined(WITH_EXAMPLEC)
	@cd ${WRKSRC}/example_c && \
		${MAKE}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example_c/example ${WRKSRC}/example_c/example_mt ${EXAMPLESDIR}
.endif

	@${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} -DMODULES_WITH_WORLD install

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

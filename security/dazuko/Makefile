# Created by: Rob Evers <rob@debank.tv>
# $FreeBSD$

PORTNAME=	dazuko
PORTVERSION=	2.3.9
CATEGORIES=	security
MASTER_SITES=	http://dazuko.dnsalias.org/files/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Common interface for 3rd party file access control

HAS_CONFIGURE=	yes
SUB_FILES=	pkg-message

BROKEN=		does not compile on freebsd version > 8.x
DEPRECATED=	Currently, the project has not an active development and maintainer
EXPIRATION_DATE=	2013-12-30

OPTIONS_DEFINE=	EXAMPLEC
OPTIONS_DEFAULT=	EXAMPLEC
EXAMPLEC_DESC=		Install C example programs

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLEC}
PLIST_FILES=	%%EXAMPLESDIR%%/example %%EXAMPLESDIR%%/example_mt
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

post-configure:
	${REINPLACE_CMD} -e 's|^NOMAN|NO_MAN|g' ${WRKSRC}/library/Makefile

do-install:
.if ${PORT_OPTIONS:MEXAMPLEC}
	@cd ${WRKSRC}/example_c && \
		${MAKE}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example_c/example ${WRKSRC}/example_c/example_mt ${EXAMPLESDIR}
.endif

	@${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} -DMODULES_WITH_WORLD install

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

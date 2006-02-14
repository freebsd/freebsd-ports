# New ports collection makefile for:	libprelude
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libprelude
PORTVERSION=	0.9.5
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Framework library for Prelude NIDS

LIB_DEPENDS=	gnutls.15:${PORTSDIR}/security/gnutls

USE_GPG=		yes
SIG_SUFFIX=		.sig
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
INSTALLS_SHLIB=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--localstatedir=/var

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--enable-perl
PLIST_SUB+=		WITH_PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		WITH_PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	libprelude
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libprelude
PORTVERSION=	0.9.8
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/ \
		http://www.prelude-ids.org/download/releases/old/

MAINTAINER=	r.gruyters@yirdis.nl
COMMENT=	Framework library for Prelude NIDS

LIB_DEPENDS=	gnutls.15:${PORTSDIR}/security/gnutls

USE_GPG=		yes
SIG_SUFFIX=		.sig
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--localstatedir=/var

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

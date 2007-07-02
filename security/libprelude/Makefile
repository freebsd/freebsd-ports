# New ports collection makefile for:	libprelude
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libprelude
PORTVERSION=	0.9.14
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/ \
		http://www.prelude-ids.org/download/releases/old/

MAINTAINER=	r.gruyters@yirdis.nl
COMMENT=	Framework library for Prelude NIDS

LIB_DEPENDS=	gnutls.13:${PORTSDIR}/security/gnutls

OPTIONS=	PERL "Include Perl bindings" off \
		PYTHON "Include Python bindings" off

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--localstatedir=/var

.include <bsd.port.pre.mk>

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		2.3+
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}

	@if [ ! -f ${PREFIX}/etc/prelude/default/client.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude/default/client.conf-dist \
	      ${PREFIX}/etc/prelude/default/client.conf ; \
	fi

	@if [ ! -f ${PREFIX}/etc/prelude/default/global.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude/default/global.conf-dist \
	      ${PREFIX}/etc/prelude/default/global.conf ; \
	fi

	@if [ ! -f ${PREFIX}/etc/prelude/default/idmef-client.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude/default/idmef-client.conf-dist \
	      ${PREFIX}/etc/prelude/default/idmef-client.conf ; \
	fi

	@if [ ! -f ${PREFIX}/etc/prelude/default/tls.conf ]; then \
	   ${CP} -p ${PREFIX}/etc/prelude/default/tls.conf-dist \
	      ${PREFIX}/etc/prelude/default/tls.conf ; \
	fi

.endif

.include <bsd.port.post.mk>

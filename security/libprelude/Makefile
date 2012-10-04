# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libprelude
PORTVERSION=	0.9.24.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-technologies.com/download/releases/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework library for Prelude NIDS

LIB_DEPENDS=	gnutls.47:${PORTSDIR}/security/gnutls \
		gcrypt.18:${PORTSDIR}/security/libgcrypt

OPTIONS_DEFINE=	PERL PYTHON DOCS

BROKEN=		does not configure

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-gtk-doc=no \
		--with-html-dir=${PREFIX}/share/doc

MAN1=		prelude-admin.1
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=		yes
.include "${PORTSDIR}/Mk/bsd.perl.mk"
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		WITH_PYTHON="" PYTHON_VER=${PYTHON_VER}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' ${WRKSRC}/src/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif
	@${INSTALL_MAN} ${WRKSRC}/docs/manpages/*.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL_DATA} ${WRKSRC}/client.conf \
	                ${PREFIX}/etc/prelude/default/client.conf-dist
	@${INSTALL_DATA} ${WRKSRC}/global.conf \
	                ${PREFIX}/etc/prelude/default/global.conf-dist
	@${INSTALL_DATA} ${WRKSRC}/tls.conf \
	                ${PREFIX}/etc/prelude/default/tls.conf-dist
	@${INSTALL_DATA} ${WRKSRC}/idmef-client.conf \
	                ${PREFIX}/etc/prelude/default/idmef-client.conf-dist

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

.include <bsd.port.post.mk>

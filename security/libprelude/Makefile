# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libprelude
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.prelude-ids.org/attachments/download/241/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework library for Prelude NIDS

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		nettle:${PORTSDIR}/security/nettle \
		p11-kit:${PORTSDIR}/security/p11-kit

OPTIONS_DEFINE=	PERL PYTHON DOCS

USE_AUTOTOOLS=	libtool libltdl
CONFIGURE_ARGS=	--localstatedir=/var \
		--enable-gtk-doc=no \
		--with-html-dir=${PREFIX}/share/doc
USE_GMAKE=	yes
USE_PKGCONFIG=	build
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		prelude-admin.1
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-perl
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--without-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CONFIGURE_ARGS+=--with-python
PLIST_SUB+=	PYTHON="" PYTHON_VER="${PYTHON_VER}" VERSION="${PORTVERSION}"
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-data-local||' ${WRKSRC}/docs/api/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/*.1 ${MAN1PREFIX}/man/man1
.for f in client.conf global.conf idmef-client.conf tls.conf
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${PREFIX}/etc/prelude/default/${f}-dist
.if !exists(${PREFIX}/etc/prelude/default/${f})
	(cd ${PREFIX}/etc/prelude/default && ${CP} -p ${f}-dist ${f})
.endif
.endfor
.if ${PORT_OPTIONS:MPERL}
	-@${RM} -f ${PREFIX}/lib/perl5/${PERL_VERSION}/${PERL_ARCH}/perllocal.pod
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

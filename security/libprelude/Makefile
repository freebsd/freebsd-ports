# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libprelude
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/attachments/download/241/

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Framework library for Prelude NIDS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.README

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libnettle.so:${PORTSDIR}/security/nettle \
		libp11-kit.so:${PORTSDIR}/security/p11-kit

OPTIONS_DEFINE=	DOCS PERL PYTHON
OPTIONS_SUB=	yes

USES=		charsetfix gettext gmake iconv libtool pathfix pkgconfig
USE_AUTOTOOLS=	libltdl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--localstatedir=/var \
		--enable-gtk-doc=no \
		--with-html-dir=${PREFIX}/share/doc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

ETCDIR=		${PREFIX}/etc/prelude
PORTDOCS=	*

PERL_CONFIGURE_WITH=	perl
PERL_USES=		perl5
PYTHON_CONFIGURE_WITH=	python
PYTHON_USES=		python

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
PLIST_SUB+=	PYTHON_VER="${PYTHON_VER}" VERSION="${PORTVERSION}"
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} '\,gnutls/extra\.h,d' \
		${WRKSRC}/prelude-admin/prelude-admin.c \
		${WRKSRC}/prelude-admin/server.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/manpages/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.for f in client.conf global.conf idmef-client.conf tls.conf
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${ETCDIR}/default/${f}.sample
	${RM} ${STAGEDIR}${ETCDIR}/default/${f}	# Remove files install-data-local installs
.endfor

.if ${PORT_OPTIONS:MPERL}
	-@${RM} -f ${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH}/perllocal.pod
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/api/html/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>

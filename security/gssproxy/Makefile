PORTNAME=	gssproxy
DISTVERSION=	0.9.2
CATEGORIES=	security
MASTER_SITES=	https://github.com/gssapi/gssproxy/releases/download/v${DISTVERSION}/

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	GSSAPI proxy daemon and interposer mechanism
WWW=		https://github.com/gssapi/gssproxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libgssrpc.so.4:security/krb5 \
		libini_config.so:devel/ding-libs \
		libpopt.so:devel/popt \
		libverto.so.0:security/krb5

USES=		autoreconf gettext-runtime gmake gssapi:mit libtool localbase \
		pkgconfig

USE_RC_SUBR=	gssproxy

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-cc-path=/var/db/gssproxy/clients \
		--with-gpstate-path=/var/db/gssproxy \
		--with-gssconf-path=${PREFIX}/etc/gss/mech.d \
		--with-initscript=none \
		--with-log-path=/var/log/gssproxy \
		--with-manpages \
		--with-pid-file=/var/run/gssproxy.pid \
		--with-pubconf-path=${PREFIX}/etc/gssproxy \
		--with-socket-name=/var/run/gssproxy.sock \
		--with-xml-catalog-path=${LOCALBASE}/share/xml/catalog \
		--without-cap \
		--without-selinux
CONFIGURE_ENV=	ac_cv_func_verto_cleanup=no

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
LIBS+=		-lepoll-shim -lintl

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/gssproxy/proxymech.la
	${RM} -r ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/etc/gss/mech.d/proxymech.conf \
		${STAGEDIR}${PREFIX}/etc/gss/mech.d/proxymech.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gssproxy
	${INSTALL_DATA} ${WRKSRC}/examples/gssproxy.conf \
		${STAGEDIR}${PREFIX}/etc/gssproxy/gssproxy.conf.sample
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/24-nfs-server.conf \
		${STAGEDIR}${EXAMPLESDIR}/24-nfs-server.conf
	${INSTALL_DATA} ${WRKSRC}/examples/80-httpd.conf \
		${STAGEDIR}${EXAMPLESDIR}/80-httpd.conf
	${INSTALL_DATA} ${WRKSRC}/examples/99-network-fs-clients.conf \
		${STAGEDIR}${EXAMPLESDIR}/99-network-fs-clients.conf
	${MKDIR} ${STAGEDIR}/var/db/gssproxy/clients
	${MKDIR} ${STAGEDIR}/var/db/gssproxy/rcache
	${MKDIR} ${STAGEDIR}/var/log/gssproxy

.include <bsd.port.mk>

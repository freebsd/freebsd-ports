PORTNAME=	am-utils
PORTVERSION=	6.2
PORTREVISION=	14
PORTEPOCH=	1
CATEGORIES=	sysutils net
MASTER_SITES=	https://download.filesystems.org/am-utils/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/amd/am-utils/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Berkeley Automounter Suite of Utilities
WWW=		https://www.am-utils.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	OPENLDAP DOCS
OPTIONS_DEFAULT=OPENLDAP
OPENLDAP_DESC=	OpenLDAP support

USES=		autoreconf:build bison libtool makeinfo perl5
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX= ${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared
# Enable some filesystems which are not auto-detected with GENERIC kernel.
CONFIGURE_ARGS+=	ac_cv_fs_mfs=yes ac_cv_mnttab_type_nullfs='"mfs"' ac_cv_mount_type_nullfs='"mfs"' \
			ac_cv_fs_nullfs=yes ac_cv_mnttab_type_nullfs='"nullfs"' ac_cv_mount_type_nullfs='"nullfs"' \
			ac_cv_fs_udf=yes ac_cv_mnttab_type_udf='"udf"' ac_cv_mount_type_udf='"udf"' \
			ac_cv_fs_tmpfs=yes ac_cv_mnttab_type_tmpfs='"tmpfs"' ac_cv_mount_type_tmpfs='"tmpfs"'
MAKE_ENV=	MAKEINFOFLAGS=--no-split
INSTALL_TARGET=	install-strip

INFO=		am-utils
PORTDOCS=	AUTHORS BUGS FAQ NEWS README.attrcache

OPENLDAP_USES=			ldap localbase:ldflags
OPENLDAP_CONFIGURE_WITH=	ldap
OPENLDAP_PORTDOCS=		README.ldap ldap-id.txt ldap.schema

OPTIONS_SUB=	yes

.if !exists(/etc/rc.d/amd)
USE_RC_SUBR=	amd
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${RM} ${WRKSRC}/doc/am-utils.info*


.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1500059)
post-configure:
	@${ECHO_CMD} '#undef HAVE_RPC_AUTH_DES_H' >> ${WRKSRC}/config.h
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

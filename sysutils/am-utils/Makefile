# Created by: Jon Wilson <jon@phuq.co.uk>
# $FreeBSD$

PORTNAME=	am-utils
PORTVERSION=	6.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.am-utils.org/pub/am-utils/ \
		ftp://ftp.cs.umn.edu/pub/am-utils/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/amd/am-utils/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Berkeley Automounter Suite of Utilities

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	OPENLDAP DOCS
OPTIONS_DEFAULT=OPENLDAP
OPENLDAP_DESC=	OpenLDAP support

USES=		autoreconf:build bison libtool makeinfo perl5
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes
GNU_CONFIGURE=	yes
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

OPENLDAP_USES=			localbase:ldflags
OPENLDAP_USE=			OPENLDAP=yes
OPENLDAP_CONFIGURE_WITH=	ldap
OPENLDAP_PORTDOCS=		README.ldap ldap-id.txt ldap.schema

OPTIONS_SUB=	yes

post-patch:
	@${RM} ${WRKSRC}/doc/am-utils.info*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

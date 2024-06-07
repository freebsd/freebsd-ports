PORTNAME=	realmd
PORTVERSION=	0.17.1
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	DBus service for configuring kerberos and other online identities
WWW=		https://www.freedesktop.org/software/realmd/

LICENSE=	LGPL21

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USES=		autoreconf gettext gmake gnome gssapi:mit,flags iconv ldap \
		libtool localbase pathfix pkgconfig ssl tar:bz2
USE_GNOME=	glib20

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	realmd

GNU_CONFIGURE=	yes
TEST_TARGET=	check

BINARY_ALIAS=   sed=${LOCALBASE}/bin/gsed

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	${GSSAPI_CONFIGURE_ARGS} \
		--with-distro=freebsd \
		--without-systemd-journal \
		--without-systemd-unit-dir
CONFIGURE_ENV+=	KRB5_CONFIG=${KRB5CONFIG}

DOCS_CONFIGURE_ENABLE=	doc
DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			xsltproc:textproc/libxslt \
			xmlto:textproc/xmlto

SUB_FILES=	realmd-freebsd.conf
SUB_LIST=	SAMBA=samba${SAMBA_DEFAULT:S/.//}

post-patch:
	@${REINPLACE_CMD} -e 's/INSTALL_PROGRAM/INSTALL_DATA/g' ${WRKSRC}/service/Makefile.am

pre-install:
	@${INSTALL_DATA} ${WRKDIR}/realmd-freebsd.conf ${WRKSRC}/service/realmd-freebsd.conf

.include <bsd.port.mk>

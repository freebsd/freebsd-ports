# New ports collection makefile for:	opensc
# Date created:		10 September 2002
# Whom:			Bruce M Simpson
#
# $FreeBSD$
#

PORTNAME=	opensc
PORTVERSION=	0.12.0
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/ \
		http://www.opensc-project.org/files/${PORTNAME}/testing/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access smart cards

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

OPTIONS=	PCSC "Enable PC/SC backend support" on \
		OPENCT "Enable direct OpenCT backend support" off \
		CTAPI "Enable CT-API backend support" off

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libltdl
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl" \
		XSLTPROC="${LOCALBASE}/bin/xsltproc"

CONFIGURE_ARGS=	--with-xsl-stylesheetsdir=${LOCALBASE}/share/xsl/docbook

PORTDOCS=	*

MANCOMPRESSED=	no
MAN1=		cardos-tool.1 cryptoflex-tool.1 netkey-tool.1 \
		opensc-explorer.1 opensc-tool.1 \
		pkcs11-tool.1 pkcs15-crypt.1 pkcs15-init.1 pkcs15-tool.1 \
		westcos-tool.1
MAN5=		pkcs15-profile.5

.include <bsd.port.options.mk>

.if defined(WITH_OPENCT)
LIB_DEPENDS+=	openct.1:${PORTSDIR}/security/openct
CONFIGURE_ARGS+=--enable-openct
.endif

.if !defined(WITHOUT_PCSC)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
.else
CONFIGURE_ARGS+=--disable-pcsc
.endif

.if defined(WITH_CTAPI)
CONFIGURE_ARGS+=--enable-ctapi
.endif

.ifndef(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-doc
.endif

post-patch:
	@${REINPLACE_CMD} 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/configure
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|install-data-am: install-htmlDATA install-man|install-data-am: install-man|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

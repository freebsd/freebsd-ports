# New ports collection makefile for:	openct
# Date created:		2004-09-08
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	openct
PORTVERSION=	0.6.16
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/ \
		http://www.opensc-project.org/files/${PORTNAME}/testing/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A middleware framework for smart card terminals

OPTIONS=	PCSC "Enable PC/SC support" off

USE_AUTOTOOLS=	libltdl:15
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	openct
SUB_FILES=	etoken.conf

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl"

CONFIGURE_ARGS=	--localstatedir=/var

MAN1=		openct-tool.1

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800069
CONFIGURE_ENV+=	LIBUSB_CFLAGS="-I/usr/include" \
		LIBUSB_LIBS="-lusb"

CONFIGURE_ARGS+=--enable-usb
.endif

.if defined(WITH_PCSC)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
CONFIGURE_ARGS+=--enable-pcsc
PLIST_SUB+=	PCSC=""
.else
PLIST_SUB+=	PCSC="@comment "
.endif

.ifndef(NOPORTDOCS)
CONFIGURE_ARGS+=--enable-doc
.endif

post-patch:
	@${REINPLACE_CMD} 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/configure
.ifndef(NOPORTDOCS)
	@${REINPLACE_CMD} 's|install-data-am: install-apidocDATA install-dist_docDATA|install-data-am: install-dist_docDATA|' \
		${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|install-data-am: install-apidocDATA install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKDIR}/etoken.conf ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# ports collection makefile for: gimp-print
# Date Created: 2002 01 02
# Whom: dgilbert@velocet.ca

# $FreeBSD$

PORTNAME=	gimp-print
PORTVERSION=	4.2.6
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP Print Printer Driver

USE_GETTEXT=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-gimp=no
INSTALLS_SHLIB=	yes

MAN1=	escputil.1 gimpprint-config.1 ijsgimpprint.1
MAN3=	gimpprint.3
MAN7=	gimpprint-color.7 gimpprint-dithers.7 gimpprint-imagetypes.7 \
	gimpprint-inktypes.7 gimpprint-mediasizes.7 gimpprint-mediasources.7 \
	gimpprint-mediatypes.7 gimpprint-models.7 gimpprint-resolutions.7
MAN8=	cups-calibrate.8
INFO=	gimpprint

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_CUPS)
PLIST_SUB+=	CUPS="@comment "
.else
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS+=	espgs:${PORTSDIR}/print/cups-pstoraster
CONFIGURE_ARGS+=	--with-cups=${PREFIX}
PLIST_SUB+=	CUPS=""
.endif

.if defined(WITHOUT_IJS)
PLIST_SUB+=	IJS="@comment "
.else
LIB_DEPENDS+=	ijs.1:${PORTSDIR}/print/libijs
CONFIGURE_ARGS+=	--with-ijs=yes
PLIST_SUB+=	IJS=""
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-user-guide=no
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "	WITHOUT_CUPS=yes	build without CUPS driver"
	@${ECHO_MSG} "	WITHOUT_IJS=yes 	build without IJS-based Ghostscript driver"
	@${ECHO_MSG}

post-extract:
	@${RM} -f ${WRKSRC}/doc/gimpprint.info*

post-patch:
	@${REINPLACE_CMD} -e 's|=makeinfo|="makeinfo --no-split"|g ; \
		 s|$${CFLAGS:=} -O|$${CFLAGS}|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(PACKAGE)/doc|doc/$$(PACKAGE)|g ; \
		 s|$$(RM) -r|$$(RM) -f -r|g'

.include <bsd.port.mk>

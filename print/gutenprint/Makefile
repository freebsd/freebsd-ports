# ports collection makefile for: gimp-print
# Date Created: 2002 01 02
# Whom: dgilbert@velocet.ca
#
# $FreeBSD$
#    $MCom: ports/print/gutenprint/Makefile,v 1.3 2006/02/25 00:13:44 marcus Exp $
#

PORTNAME=	gutenprint
PORTVERSION=	5.0.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gimp-print

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GutenPrint Printer Driver

CONFLICTS=	gimp-print-[0-9]*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-gimp=no --with-gimp2=no \
		--without-foomatic
INSTALLS_SHLIB=	yes

MAN1=	escputil.1 ijsgutenprint.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_CUPS) && !defined(WITHOUT_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS+=	espgs:${PORTSDIR}/print/cups-pstoraster
CONFIGURE_ARGS+=	--with-cups=${PREFIX}
PLIST_SUB+=	CUPS=""
MAN8=	cups-calibrate.8 cups-genppd.8 cups-genppdconfig.8 \
	cups-genppdupdate.8
.else
PLIST_SUB+=	CUPS="@comment "
CONFIGURE_ARGS+=	--without-cups
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
	@${ECHO_MSG} "	WITH_CUPS=yes		build with CUPS driver"
	@${ECHO_MSG} "	WITHOUT_IJS=yes 	build without IJS-based Ghostscript driver"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|$$libdir/gimp/1.2/plug-ins||g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>

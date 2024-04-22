PORTNAME=	foomatic-filters
PORTVERSION=	4.0.17
PORTREVISION=	12
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Foomatic wrapper scripts
WWW=		https://www.openprinting.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe ghostscript perl5 pkgconfig
CPE_VENDOR=	linuxfoundation
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	ac_cv_path_A2PS=${LOCALBASE}/bin/a2ps \
		ac_cv_path_CUPS=${LOCALBASE}/libexec/cups \
		ac_cv_path_CUPS_BACKENDS=${LOCALBASE}/libexec/cups/backend \
		ac_cv_path_CUPS_FILTERS=${LOCALBASE}/libexec/cups/filter \
		ac_cv_path_ENSCRIPT=${LOCALBASE}/bin/enscript \
		ac_cv_path_MPAGE=${LOCALBASE}/bin/mpage \
		ac_cv_path_PERL=${LOCALBASE}/bin/perl \
		ac_cv_path_PPR=${LOCALBASE}/lib/ppr \
		ac_cv_path_PPR_INTERFACES=${LOCALBASE}/lib/ppr/interfaces \
		ac_cv_path_PPR_LIB=${LOCALBASE}/lib/ppr/lib \
		ac_cv_path_TEXTTOPS=${LOCALBASE}/libexec/cups/filter/texttops

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS=	cups-filters

OPTIONS_DEFINE=		A2PS CUPS_IMAGE DBUS MPAGE
OPTIONS_DEFAULT=	A2PS CUPS_IMAGE DBUS ENSCRIPT_A4 MPAGE
OPTIONS_RADIO=		ENSCRIPT
OPTIONS_RADIO_ENSCRIPT=	ENSCRIPT_A4 ENSCRIPT_LETTER ENSCRIPT_LETTERDJ

A2PS_DESC=		Install a2ps convertor
CUPS_IMAGE_DESC=	Install cups image utilities
ENSCRIPT_A4_DESC=	Install enscript convertor (A4)
ENSCRIPT_LETTERDJ_DESC=	Install enscript convertor (letterdj)
ENSCRIPT_LETTER_DESC=	Install enscript convertor (letter)
MPAGE_DESC=		Print multiple pages per sheet of paper

A2PS_RUN_DEPENDS=		a2ps:print/a2ps
CUPS_IMAGE_LIB_DEPENDS=		libcupsimage.so:print/cups
DBUS_LIB_DEPENDS=		libdbus-1.so:devel/dbus
DBUS_CONFIGURE_ENABLE=		dbus
ENSCRIPT_A4_RUN_DEPENDS=	enscript:print/enscript-a4
ENSCRIPT_LETTERDJ_RUN_DEPENDS=	enscript:print/enscript-letterdj
ENSCRIPT_LETTER_RUN_DEPENDS=	enscript:print/enscript-letter
MPAGE_RUN_DEPENDS=		mpage:print/mpage

post-patch:
	@${REINPLACE_CMD} -e 's|ln -sf $$(BINDIR)|ln -sf ../../../bin|g' \
			  -e '/filter.conf/ s|if.*||' \
			  ${WRKSRC}/Makefile.am

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/foomatic-rip

.include <bsd.port.mk>

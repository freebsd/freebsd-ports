# New ports collection makefile for:	openct
# Date created:		2004-09-08
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	openct
DISTVERSION=	0.6.13
CATEGORIES=	security
MASTER_SITES=	http://www.opensc-project.org/files/${PORTNAME}/ \
		http://www.opensc-project.org/files/${PORTNAME}/testing/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A middleware framework for smart card terminals

OPTIONS=	USB "Install libusb for USB tokens/readers support" on \
		PCSC "Install pcsc-lite to build the PC/SC->OpenCT frontend" off

USE_AUTOTOOLS=	libltdl:15
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	openct
SUB_FILES=	etoken.conf

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		openct-tool.1

DOC_FILES=	README export-wiki.sh export-wiki.xsl trac.css *.html api

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_USB) || exists(${LOCALBASE}/lib/libusb-0.1.so)
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

.if defined(WITH_PCSC) || exists(${LOCALBASE}/lib/libpcsclite.so)
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
PLIST_SUB+=	PCSC=""
.else
PLIST_SUB+=	PCSC="@comment "
.endif

post-install:
	${INSTALL_DATA}	${WRKSRC}/etc/openct.conf ${PREFIX}/etc/openct.conf-sample
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKDIR}/etoken.conf ${EXAMPLESDIR}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${CP} -R ${DOC_FILES} ${DOCSDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

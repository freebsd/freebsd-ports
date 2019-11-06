# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	asmail
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	mail afterstep
MASTER_SITES=	AFTERSTEP/apps/asmail/ \
		http://tigr.net/afterstep/download/asmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Biff-type program, designed to match AfterStep

USES=		ssl xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shaping \
		--with-xpm \
		--with-xpm-includes=${LOCALBASE}/include \
		--with-xpm-library=${LOCALBASE}/lib

LDFLAGS+=	-pthread -L${OPENSSLLIB} -lssl -lcrypto
CPPFLAGS+=	-I${OPENSSLINC}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|g ; \
		 s|machine/soundcard|sys/soundcard|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/STRIP/s|^|#| ; \
		 s| \($$(AFTER_.*DIR)\)| $$(DESTDIR)\1| ; \
		 s|\.\([0-9]\)x|.\1|' \
		${WRKSRC}/autoconf/Makefile.common.in
	@${REINPLACE_CMD} -e \
		's|@CFLAGS@ -D|@CFLAGS@ @CPPFLAGS@ -D|g ; \
		 s|-lpthread -lrt|@LDFLAGS@|g' \
		${WRKSRC}/autoconf/Makefile.defines.in
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/asmailrc.sample

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} asmailrc.sample \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

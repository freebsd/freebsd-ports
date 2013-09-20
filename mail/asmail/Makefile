# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	asmail
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	mail afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Biff-type program, designed to match AfterStep

USE_XORG=	xpm
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shaping \
		--with-xpm \
		--with-xpm-includes=${LOCALBASE}/include \
		--with-xpm-library=${LOCALBASE}/lib

MAN1=	asmail.1x
MAN5=	asmailrc.5x

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -lssl -lcrypto

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|machine/soundcard|sys/soundcard|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@CFLAGS@ -D|@CFLAGS@ @CPPFLAGS@ -D|g ; \
		 s|-lpthread -lrt|@LDFLAGS@|g' ${WRKSRC}/autoconf/Makefile.defines.in
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}|g' ${WRKSRC}/asmailrc.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/asmailrc.sample ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

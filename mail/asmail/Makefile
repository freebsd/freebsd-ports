# New ports collection makefile for:	 asmail
# Date created:		15 August 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	asmail
PORTVERSION=	1.7
CATEGORIES=	mail afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Biff-type program, designed to match AfterStep

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shaping

MAN1=	asmail.1x
MAN5=	asmailrc.5x

post-patch:
.for file in configure autoconf/Makefile.defines.in
	@${REINPLACE_CMD} -e 's|-lpthread -lrt|${PTHREAD_LIBS}|g ; \
		 s|-lssl|-lcrypto -lssl|g ; \
		 s|-D_REENTRANT|-D_REENTRANT ${PTHREAD_CFLAGS}|g ; \
		 s|machine/soundcard|sys/soundcard|g' ${WRKSRC}/${file}
.endfor
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

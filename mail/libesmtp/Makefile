# New ports collection makefile for:    libesmtp
# Date created:         Sun Feb 21 2001
# Whom:                 tobez@tobez.org
#
# $FreeBSD$

PORTNAME=	libesmtp
PORTVERSION=	0.8.9
CATEGORIES=	mail
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/ \
		http://www.borgsdemons.com/distfiles/

MAINTAINER=	jmcoopr@webmail.bmi.net

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"

# require-all-recipients (implied by enable-all) is required for Balsa-1.3.x
CONFIGURE_ARGS=	--enable-all

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Notes ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

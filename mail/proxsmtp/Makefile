# New ports collection makefile for:	proxsmtp
# Date created:		2005-05-03
# Whom:			Dario Freni <saturnero@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	proxsmtp
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	http://memberwebs.com/nielsen/software/proxsmtp/

MAINTAINER=	saturnero@gufi.org
COMMENT=	A flexible SMTP filter which can act also as transparent proxy

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

USE_RC_SUBR=	proxsmtpd.sh
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN5=		proxsmtpd.conf.5
MAN8=		proxsmtpd.8

PORTDOCS=	*

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/proxsmtpd.conf ${PREFIX}/etc/proxsmtpd.conf-sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

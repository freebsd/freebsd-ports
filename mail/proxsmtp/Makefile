# New ports collection makefile for:	proxsmtp
# Date created:		2005-05-03
# Whom:			Dario Freni <saturnero@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	proxsmtp
PORTVERSION=	1.8
CATEGORIES=	mail security
MASTER_SITES=	http://memberwebs.com/stef/software/proxsmtp/

MAINTAINER=	saturnero@gufi.org
COMMENT=	A flexible SMTP filter which can act also as transparent proxy

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

USE_RC_SUBR=	proxsmtpd
SUB_FILES=	pkg-message

MAN5=		proxsmtpd.conf.5
MAN8=		proxsmtpd.8

PORTDOCS=	ChangeLog NEWS README

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/proxsmtpd.conf ${PREFIX}/etc/proxsmtpd.conf-sample
	@if [ ! -f ${PREFIX}/etc/proxsmtpd.conf ]; then \
	${CP} -p ${PREFIX}/etc/proxsmtpd.conf-sample ${PREFIX}/etc/proxsmtpd.conf ; fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

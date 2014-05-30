# Created by: Dario Freni <saturnero@gufi.org>
# $FreeBSD$

PORTNAME=	proxsmtp
PORTVERSION=	1.10
CATEGORIES=	mail security
MASTER_SITES=	http://thewalter.net/stef/software/proxsmtp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible SMTP filter which can act also as transparent proxy

LICENSE=	BSD

USES=		gmake
GNU_CONFIGURE=	yes

USE_RC_SUBR=	proxsmtpd
SUB_FILES=	pkg-message

MAN5=		proxsmtpd.conf.5
MAN8=		proxsmtpd.8

PORTDOCS=	ChangeLog NEWS README

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		'/^acx_pthread_flags/s|=.*|="${PTHREAD_LIBS}"|' \
		${WRKSRC}/configure

post-install:
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} proxsmtpd.conf \
		${PREFIX}/etc/proxsmtpd.conf-sample)
.if !exists(${PREFIX}/etc/proxsmtpd.conf)
	(cd ${PREFIX}/etc && ${CP} -p proxsmtpd.conf-sample \
		${PREFIX}/etc/proxsmtpd.conf)
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${docs} ${DOCSDIR})
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
